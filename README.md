# UpTime

UpTime [Native Extension](https://www.defold.com/manuals/extensions/) for the [Defold Game Engine](https://www.defold.com) 

This Defold Native Extension allows receiving a system uptime.
**This timer resets when user restarts their device!**

## Possible use cases

* If you want to use a timer for restore lives (or something else) in your game without server but want to have better protection against cheaters who just change system time.
* Seed for math.randomseed() (thanks @dragosha for that use case idea)

## Platforms

* **iOS**
* **MacOS**
* **Android**
* **Windows**

## Installation
To use this library in your Defold project, add the needed version URL to your `game.project` dependencies from [Releases](https://github.com/AGulev/defold-extension-uptime/releases)

<img width="401" alt="image" src="https://user-images.githubusercontent.com/2209596/202223571-c77f0304-5202-4314-869d-7a90bbeec5ec.png">

## API

#### `uptime.get()`

Returns system uptime in seconds.

```lua
local function update_uptime(self)
  if uptime then
    local uptime = uptime.get()
    print(uptime) -- 809031
  end
end

```

## Issues and suggestions

If you have any issues, questions or suggestions please [create an issue](https://github.com/AGulev/uptime/issues) or contact me: me@agulev.com
