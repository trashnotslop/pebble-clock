# [Pebble Clock](../README.md) -> Watchface

The Pebble watchface component of the [Pebble Clock](https://trashnotslop.com/projects/pebble-clock/) project from [Trash Not Slop](https://trashnotslop.com).

## Building & running

```sh
pebble build                          # build for all targetPlatforms
pebble install --emulator emery       # install on the emery emulator
pebble install --phone <ip>           # install to a paired phone
```

## Project layout

```
src/c/           C source for the watchapp
src/pkjs/        PebbleKit JS source for the config page
resources/       Images, fonts, and other bundled resources
package.json     Project metadata (UUID, platforms, resources, message keys)
wscript          Build rules — usually no need to edit
```

## Pebble Documentation

Full Pebble SDK docs, tutorials, and API reference: <https://developer.repebble.com>
