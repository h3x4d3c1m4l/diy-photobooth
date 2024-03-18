
use crate::{models::images::{MomentoBoothExifTag, RawImage}, utils::{image_processing::{self, ImageOperation}, jpeg}};

pub fn jpeg_encode(raw_image: RawImage, quality: u8, exif_tags: Vec<MomentoBoothExifTag>, operations_before_encoding: Vec<ImageOperation>) -> Vec<u8> {
    let processed_image = image_processing::execute_operations(&raw_image, &operations_before_encoding);
    jpeg::encode_raw_to_jpeg(processed_image, quality, exif_tags)
}

pub fn jpeg_decode(jpeg_data: Vec<u8>, operations_after_decoding: Vec<ImageOperation>) -> RawImage {
    let image = jpeg::decode_jpeg_to_rgba(&jpeg_data);
    image_processing::execute_operations(&image, &operations_after_decoding)
}

pub fn get_momento_booth_exif_tags_from_file(image_file_path: String) -> Vec<MomentoBoothExifTag> {
    jpeg::get_momento_booth_exif_tags_from_file(&image_file_path)
}
