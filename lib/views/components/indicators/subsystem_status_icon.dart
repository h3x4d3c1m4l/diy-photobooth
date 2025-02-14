import 'package:fluent_ui/fluent_ui.dart';
import 'package:lucide_icons_flutter/lucide_icons.dart';
import 'package:momento_booth/models/subsystem_status.dart';

class SubsystemStatusIcon extends StatelessWidget {

  final SubsystemStatus status;

  const SubsystemStatusIcon({super.key, required this.status});

  IconData? get _icon => switch (status) {
        SubsystemStatusInitial() || SubsystemStatusBusy() => LucideIcons.circleEllipsis,
        SubsystemStatusOk() => LucideIcons.circleCheckBig,
        SubsystemStatusDisabled() => LucideIcons.ban,
        SubsystemStatusWarning() => LucideIcons.circleAlert,
        SubsystemStatusError() => LucideIcons.circleX,
        SubsystemStatusWithChildren() => null,
      };

  Color get _iconColor => switch (status) {
        SubsystemStatusInitial() => Colors.grey,
        SubsystemStatusBusy() => Colors.blue,
        SubsystemStatusOk() => Colors.successPrimaryColor,
        SubsystemStatusDisabled() => Colors.grey,
        SubsystemStatusWarning() => Colors.yellow,
        SubsystemStatusError() => Colors.errorPrimaryColor,
        SubsystemStatusWithChildren() => Colors.green,
      };

  @override
  Widget build(BuildContext context) {
    return Icon(_icon, color: _iconColor);
  }

}
