use std::env;
use std::fs::File;
use std::io::Write;
use std::path::PathBuf;

fn main() {
    // Find target folder
    let out_dir = env::var("OUT_DIR").unwrap();

    // Open file "target_name.txt"
    let target_file_path = format!("{}/target_name.txt", out_dir);
    let mut file = File::create(target_file_path).unwrap();

    // Write target name to file
    let target = env::var("TARGET").unwrap();
    file.write_all(target.as_bytes()).unwrap();

    println!("cargo:rustc-link-search=../sony_sdk/precompiled_libraries/linux_x64");
    println!("cargo:rustc-link-search=../sony_sdk/precompiled_libraries/windows_x64");
    println!("cargo:rustc-link-search=../sony_sdk/precompiled_libraries/macos_x64");

    println!("cargo:rustc-link-lib=Cr_Core");

    // The bindgen::Builder is the main entry point
    // to bindgen, and lets you build up options for
    // the resulting bindings.
    let bindings = bindgen::Builder::default()
        // The input header we would like to generate
        // bindings for.
        .header("../sony_sdk/wrapper.hpp")
        // Tell cargo to invalidate the built crate whenever any of the
        // included header files changed.
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
        // Finish the builder and generate the bindings.
        .generate()
        // Unwrap the Result and panic on failure.
        .expect("Unable to generate bindings");

    // Write the bindings to the $OUT_DIR/bindings.rs file.
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
