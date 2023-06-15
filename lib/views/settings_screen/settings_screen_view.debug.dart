part of 'settings_screen_view.dart';

Widget _getDebugTab(SettingsScreenViewModel viewModel, SettingsScreenController controller) {
  return FluentSettingsPage(
    title: "Debug and Stats",
    blocks: [
      FluentSettingsBlock(
        title: "Stats",
        settings: [
          Observer(
            builder: (context) => _getTextDisplay(
              context: context,
              icon: FluentIcons.touch,
              title: "Taps",
              subtitle: "The number of taps in the app (outside settings)",
              text: StatsManager.instance.stats.taps.toString(),
            ),
          ),
          Observer(
            builder: (context) => _getTextDisplay(
              context: context,
              icon: FluentIcons.front_camera,
              title: "Live view frames",
              subtitle: "The number of live view frames processed from the start of the camera\nValue shows: Valid frames / Undecodable frames",
              text: "${StatsManager.instance.validLiveViewFrames} / ${StatsManager.instance.invalidLiveViewFrames}",
            ),
          ),
          Observer(
            builder: (context) => _getTextDisplay(
              context: context,
              icon: FluentIcons.print,
              title: "Printed pictures",
              subtitle: "The number of prints (e.g. 2 prints of the same pictures will count as 2 as well)",
              text: StatsManager.instance.stats.printedPhotos.toString(),
            ),
          ),
          Observer(
            builder: (context) => _getTextDisplay(
              context: context,
              icon: FluentIcons.upload,
              title: "Uploaded pictures",
              subtitle: "The number of uploaded pictures",
              text: StatsManager.instance.stats.uploadedPhotos.toString(),
            ),
          ),
          Observer(
            builder: (context) => _getTextDisplay(
              context: context,
              icon: FluentIcons.camera,
              title: "Captured photos",
              subtitle: "The number of photo captures (e.g. a multi capture picture would increase this by 4)",
              text: StatsManager.instance.stats.capturedPhotos.toString(),
            ),
          ),
          Observer(
            builder: (context) => _getTextDisplay(
              context: context,
              icon: FluentIcons.photo2,
              title: "Created single shot pictures",
              subtitle: "The number of single capture pictures created",
              text: StatsManager.instance.stats.createdSinglePhotos.toString(),
            ),
          ),
          Observer(
            builder: (context) => _getTextDisplay(
              context: context,
              icon: FluentIcons.undo,
              title: "Retakes",
              subtitle: "The number of retakes for (single) photo captures",
              text: StatsManager.instance.stats.retakes.toString(),
            ),
          ),
          Observer(
            builder: (context) => _getTextDisplay(
              context: context,
              icon: FluentIcons.photo_collection,
              title: "Created multi shot pictures",
              subtitle: "The number of multi shot pictures created",
              text: StatsManager.instance.stats.createdMultiCapturePhotos.toString(),
            ),
          ),
        ],
      ),
      FluentSettingsBlock(
        title: "Debug actions",
        settings: [
          _getButtonCard(
            icon: FluentIcons.error,
            title: "Report fake error",
            subtitle: "Test whether error reporting (to Sentry) works",
            buttonText: "Report Fake Error",
            onPressed: () => throw Exception("This is a fake error to test error reporting"),
          ),
          _getComboBoxCard<FilterQuality>(
            icon: FluentIcons.transition_effect,
            title: "Filter quality for screen transition",
            subtitle: "The filter quality used for the screen transition scale animation",
            items: viewModel.filterQualityOptions,
            value: () => viewModel.screenTransitionAnimationFilterQuality,
            onChanged: controller.onScreenTransitionAnimationFilterQualityChanged,
          ),
          _getComboBoxCard<FilterQuality>(
            icon: FluentIcons.front_camera,
            title: "Filter quality for live view",
            subtitle: "The filter quality used for the live view",
            items: viewModel.filterQualityOptions,
            value: () => viewModel.liveViewFilterQuality,
            onChanged: controller.onLiveViewFilterQualityChanged,
          ),
        ],
      )
    ],
  );
}
