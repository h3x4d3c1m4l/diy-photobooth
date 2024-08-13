# Sony Camera Remote SDK

In the folder, a copy of the Sony Camera Remote SDK is included. The SDK is a set of APIs that allows you to control Sony cameras remotely. It can be found [here](https://support.d-imaging.sony.co.jp/app/sdk/en/index.html). For your convenience, the SDK is also included in this repository.

## Changes to the SDK

The headers of the SDK have been placed unchanged in the `headers` folder. A `wrapper.hpp` is added as necessary to make the SDK easy to use from `bindgen` and to tell `bindgen` we're using C++ instead of C.

The `precompiled_libraries` folder contains the library as provided by Sony. This library is precompiled for Windows, MacOS, and Linux and is copied unchanged from the SDK.

## License

The license as found on the Sony website is included in the `LICENSE` file.
