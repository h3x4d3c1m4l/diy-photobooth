import 'package:fluent_ui/fluent_ui.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:lottie/lottie.dart';
import 'package:momento_booth/app_localizations.dart';
import 'package:momento_booth/models/printer_issue_type.dart';
import 'package:momento_booth/views/custom_widgets/buttons/photo_booth_filled_button.dart';
import 'package:momento_booth/views/custom_widgets/buttons/photo_booth_outlined_button.dart';
import 'package:momento_booth/views/custom_widgets/dialogs/photo_booth_dialog.dart';

class PrinterIssueDialog extends StatelessWidget {

  final String printerName;
  final PrinterIssueType issueType;
  final String errorText;
  final VoidCallback onResumeQueuePressed;

  const PrinterIssueDialog({
    super.key,
    required this.printerName,
    required this.issueType,
    required this.errorText,
    required this.onResumeQueuePressed,
  });

  @override
  Widget build(BuildContext context) {
    AppLocalizations localizations = AppLocalizations.of(context)!;
    return PhotoBoothDialog(
      title: issueType.getTitle(context),
      body: Padding(
        padding: const EdgeInsets.all(32.0),
        child: Column(
          children: [
            Text(
              issueType.getBody1(context, printerName, errorText),
              style: const TextStyle(fontWeight: FontWeight.bold),
            ),
            const SizedBox(height: 16.0),
            Lottie.asset(
              'assets/animations/Animation - 1709936404300.json',
              fit: BoxFit.contain,
              alignment: Alignment.center,
              height: 200,
            ),
            const SizedBox(height: 16.0),
            Text(
              issueType.getBody2(context),
            ),
          ],
        ),
      ),
      actions: [
        PhotoBoothOutlinedButton(
          title: localizations.printerErrorIgnoreButton,
          icon: FontAwesomeIcons.clock,
          onPressed: () {
            Navigator.of(context).pop();
          },
        ),
        PhotoBoothFilledButton(
          title: localizations.printerErrorResumeQueueButton,
          icon: FluentIcons.play_resume,
          onPressed: () {
            Navigator.of(context).pop();
            onResumeQueuePressed();
          },
        ),
      ],
    );
  }

}
