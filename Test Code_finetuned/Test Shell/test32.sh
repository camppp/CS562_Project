#!/bin/bash

# Extract the version of Electron being used
ELECTRON_VERSION=$(node -e "console.log(require('./node_modules/electron/package.json').version)")

# Change directory to the node_modules/realm directory
cd node_modules/realm

# Set the HOME environment variable
export HOME=~/.electron-gyp

# Use npx to run node-pre-gyp to rebuild the Realm package
npx node-pre-gyp rebuild --build-from-source --runtime=electron --target=$ELECTRON_VERSION --arch=x64 --dist-url=https://atom.io/download/electron