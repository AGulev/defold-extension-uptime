# UpTime

UpTime [Native Extension](https://www.defold.com/manuals/extensions/) for the [Defold Game Engine](https://www.defold.com) (**iOS**, **MacOS** and **Android**).

This Defold Native Extension allows receiving a system uptime.
**This timer resets when a user restarts their device!**

Possible use case: if you want to use a timer for restore lives (or something else) in your game without server but want to have better protection against cheaters who just change system time.

## Setup

You can use the UpTime extension in your own project by adding this project as a [Defold library dependency](https://www.defold.com/manuals/libraries/). Open your game.project file and in the dependencies field under project add:

> https://github.com/AGulev/uptime/archive/master.zip

Or point to the ZIP file of a [specific release](https://github.com/AGulev/uptime/releases).

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
