# W2H

Microsoft Word 1.1 on Haiku.

W2H explores a native Haiku execution surface for the historical Word 1.1a /
Opus application semantics.

It is not a Wine port and does not implement a general Win16 compatibility
environment. The project instead maps only the semantics Word requires onto
native Haiku facilities.

The current foundation provides a native Haiku application, window, drawing
view, font metrics, and keyboard-to-BMessage interaction.

No Microsoft Word source or assets are included in this repository.

## Build

W2H currently targets Haiku x86_64 with the native development tools.

    make

Run the application with:

    ./build/W2H

Remove generated build products with:

    make clean

List the public build targets with:

    make help
