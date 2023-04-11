use flutter_rust_bridge::{StreamSink, ZeroCopyBuffer};

use crate::{hardware_control::live_view::nokhwa::{self, NokhwaCameraInfo}, utils::ffsend_client::{self, FfSendTransferProgress}, LogEvent, HardwareInitializationFinishedEvent};

pub fn initialize_log(log_sink: StreamSink<LogEvent>) {
    crate::initialize_log(log_sink);
}

pub fn initialize_hardware(ready_sink: StreamSink<HardwareInitializationFinishedEvent>) {
    crate::initialize_hardware(ready_sink);
}

pub fn nokhwa_get_cameras() -> Vec<NokhwaCameraInfo> {
    nokhwa::get_cameras()
}

pub fn nokhwa_open_camera(camera_info: NokhwaCameraInfo, new_image_event_sink: StreamSink<ZeroCopyBuffer<Vec<u8>>>) {
    nokhwa::open_camera(camera_info, new_image_event_sink)
}

pub fn nokhwa_close_camera() {
}

// ////// //
// ffsend //
// ////// //

pub fn ffsend_upload_file(host_url: String, file_path: String, download_filename: Option<String>, max_downloads: Option<u8>, expires_after_seconds: Option<usize>, update_sink: StreamSink<FfSendTransferProgress>) {
    ffsend_client::upload_file(host_url, file_path, download_filename, max_downloads, expires_after_seconds, update_sink)
}

pub fn ffsend_delete_file(file_id: String) {
    ffsend_client::delete_file(file_id)
}
