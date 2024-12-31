import 'dart:async';
import 'dart:math';

import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:mobx/mobx.dart';
import 'package:momento_booth/main.dart';
import 'package:momento_booth/managers/_all.dart';
import 'package:momento_booth/models/subsystem_status.dart';
import 'package:momento_booth/utils/subsystem.dart';

class OnboardingPage extends StatefulWidget {

  const OnboardingPage({super.key});

  @override
  State<OnboardingPage> createState() => _OnboardingPageState();

}

class _OnboardingPageState extends State<OnboardingPage> {

  static const int _gradientCount = 3;

  final _random = Random();
  late List<Gradient> _gradients;

  @override
  void initState() {
    _updateGradients();

    Timer.periodic(
      const Duration(seconds: 10),
      (_) => _updateGradients(),
    );

    WidgetsBinding.instance.addPostFrameCallback((timeStamp) => _updateGradients());

    super.initState();
  }

  void _updateGradients() {
    setState(() {
      _gradients = List.generate(
          _gradientCount,
          (i) => RadialGradient(
                radius: _random.nextDouble() / 3 + 0.30,
                center: Alignment(
                  _random.nextDouble() * (_random.nextBool() ? -1 : 1),
                  _random.nextDouble() * (_random.nextBool() ? -1 : 1),
                ),
                focalRadius: 100,
                colors: [
                  _getRandomLightBlueTint(),
                  const Color.fromARGB(0, 255, 255, 255),
                ],
              ),
          growable: false);
    });
  }

  Color _getRandomLightBlueTint() {
    final possibleColors = [Colors.blue.light, Colors.blue.lightest];
    final chosenColor = possibleColors[_random.nextInt(possibleColors.length)];
    return chosenColor.withOpacity(_random.nextDouble());
  }

  @override
  Widget build(BuildContext context) {
    //final FluentThemeData themeData = FluentTheme.of(context);
    ObservableList list = getIt.get<ObservableList<Subsystem>>();
    print(list);

    return Stack(
      fit: StackFit.expand,
      children: [
        const ColoredBox(color: Colors.white),
        ..._gradients.map((g) => AnimatedContainer(
              duration: const Duration(seconds: 10),
              decoration: BoxDecoration(
                gradient: g,
              ),
            )),
        Center(
          child: SizedBox(
            width: 800,
            height: 500,
            child: _getCenterWidget(context),
          ),
        ),
        // Align(
        //   alignment: Alignment.bottomCenter,
        //   child: OnboardingVersionInfo(
        //     appVersionInfo: _appVersionInfo,
        //   ),
        // ),
      ],
    );
  }

  Widget _getCenterWidget(BuildContext context) {
    return Acrylic(
      elevation: 16.0,
      luminosityAlpha: 0.9,
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(4.0)),
      child: Column(
        children: [
          Expanded(
            child: Column(
              children: [
                Text(
                  "Initializing app",
                  style: FluentTheme.of(context).typography.title,
                ),
                Observer(
                  builder: (context) => Column(
                    children: [
                      _subsystemStatusCard("Window manager", getIt<WindowManager>().subsystemStatus, context),
                      _subsystemStatusCard("Settings", getIt<SettingsManager>().subsystemStatus, context),
                      _subsystemStatusCard("Statistics", getIt<StatsManager>().subsystemStatus, context),
                      _subsystemStatusCard("Live view", getIt<LiveViewManager>().subsystemStatus, context),
                      _subsystemStatusCard("MQTT", getIt<MqttManager>().subsystemStatus, context),
                      _subsystemStatusCard("Printing", getIt<PrintingManager>().subsystemStatus, context),
                      _subsystemStatusCard("Sounds", getIt<SfxManager>().subsystemStatus, context),
                    ],
                  ),
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }

}

Widget _subsystemStatusCard(String name, SubsystemStatus status, BuildContext context) {
  const defaultMessage = "No message";
  final String message = switch(status) {
    SubsystemStatusOk(message: var m) => m ?? defaultMessage,
    SubsystemStatusBusy(message: var m) => m,
    SubsystemStatusWarning(message: var m) => m,
    SubsystemStatusError(message: var m) => m,
    _ => defaultMessage
  };

  final ActionMap actions = switch(status) {
    SubsystemStatusOk(actions: var a) => a,
    // SubsystemStatusDeferred(actions: var a) => a,
    SubsystemStatusDisabled(actions: var a) => a,
    SubsystemStatusBusy(actions: var a) => a,
    SubsystemStatusWarning(actions: var a) => a,
    SubsystemStatusError(actions: var a) => a,
    _ => {}
  };

  return Card(
    backgroundColor: Colors.transparent,
    child: Column(
      children: [
        Text(name, style: FluentTheme.of(context).typography.subtitle),
        Text(status.toString(), style: FluentTheme.of(context).typography.bodyStrong),
        Text(message, style: FluentTheme.of(context).typography.body),
        Row(children: [
          for (final e in actions.entries)
            Button(onPressed: e.value, child: Text(e.key))
        ],)
      ],
    )
  );
}
