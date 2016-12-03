# UDP-COCKPIT

This project intents to create a system for rendering the intrument panel of a GA aircraft without requiring a copy of X-Plane running on the same PC.

This way we can have the display of the panel running anywhere the code can compile to. This can be on the same PC or another one in the same network. Technically this should not be limited to PCs, the project is intended to be eventually used on a Raspberry Pi connected to a 10-inch or bigger screen.

## Technology

To make the program as portable as possible, the project will only use cross-platform libraries.

Currently we are using two:

1. Allegro 5 - Cross-Platform 2D graphics API
2. POCO C++ - C++ class libraries for building network applications.
