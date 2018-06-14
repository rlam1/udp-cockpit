# UDP-COCKPIT

This project intents to create a system for rendering the glass cockpit of a generic aircraft without requiring a copy of X-Plane running on the same PC.

This way we can have the display of the panel running anywhere the code can compile to. This can be on the same PC or another one in the same network. Technically this should not be limited to PCs, the project is intended to be eventually used on a Raspberry Pi connected to a 7-inch or bigger screen.

## Technology

To make the program as portable as possible, the project will only use cross-platform libraries.

Currently we are using:

1. **Allegro 5** - Cross-Platform 2D graphics API
2. **POCO C++** - Class libraries for building network applications.

Both need to be correctly installed and configured. On a Linux system you will then run 'make' on either the *Debug* or *Release* directory and the binary (called by default *Viewer*) should be compiled.

Copyright (c) 2018 Rodolfo Lam. All rights reserved.
SPDX-License-Identifier: BSD-3-Clause
