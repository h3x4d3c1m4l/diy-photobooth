import 'dart:typed_data';

import 'package:momento_booth/hardware_control/printing/printing_system_client.dart';
import 'package:momento_booth/managers/settings_manager.dart';
import 'package:momento_booth/models/printer_info.dart';
import 'package:momento_booth/src/rust/api/cups.dart';
import 'package:momento_booth/src/rust/utils/ipp_client.dart';

class CupsClient extends PrintingSystemClient {

  int lastUsedPrinterIndex = -1;

  static Future<List<PrinterInfo>> getPrintQueues() async {
    List<IppPrinterState> cupsPrinters = await cupsGetPrinters(serverInfo: serverInfo);
    return cupsPrinters.map((printer) => PrinterInfo(
      id: printer.queueName,
      name: printer.description,
      isAvailable: printer.stateReason != "offline-report",
    )).toList();
 }

  @override
  Future<void> printPdf(String taskName, Uint8List pdfData) async {
    // cupsPrintJob(
    //   serverInfo: _serverInfo,
    //   queueId: abc,
    //   jobName: taskName,
    //   pdfData: pdfData,
    // );
  }

  static CupsServerInfo get serverInfo {
    return CupsServerInfo(
      uri: SettingsManager.instance.settings.hardware.cupsUri,
      username: SettingsManager.instance.settings.hardware.cupsUsername,
      password: SettingsManager.instance.settings.hardware.cupsPassword,
    );
  }

}
