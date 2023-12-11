#!/bin/bash

# Extract the version of Electron being used
ELECTRON_VERSION=$(jq -r '.dependencies.electron' package.json)

# Change directory to the node_modules/realm directory
cd node_modules/realm

# Set the HOME environment variable to ~/.electron-gyp
export HOME=~/.electron-gyp

# Use npx to run node-pre-gyp to rebuild the Realm package with the following build configurations:
# --build-from-source
# --runtime=electron
# --target=<ELECTRON_VERSION>
# --arch=x64
# --dist-url=https://atom.io/download/electron
npx node-pre-gyp rebuild --build-from-source --runtime=electron --target=$ELECTRON_VERSION --arch=x64 --dist-url=https://atom.io/download/electron