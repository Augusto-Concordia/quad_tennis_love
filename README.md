![1693238824_quad_tennis_love](https://github.com/Augusto-Concordia/quad_tennis_love/assets/33916325/e311dbbc-77a2-42be-b4db-6eac1222cb22)

# quad_tennis_love
Quiz #1 - COMP 371

## Features
* Many keybinds to control the camera and the model
* Animated and fun-shaded tennis racket with ball
* Lit model using the simple Phong Lighting model

## Getting Started
### From a zipped folder (TAs ⚠️)
All depended-on libraries should already be included in the vendor folder.

1. Generate project files with CMake
2. Set the working directory to the root of the project
3. Run the `quad_tennis_love` project!

### From the git repository
Similar to the above instructions, with the key difference being to clone the repository with `--recurse-submodules` to include the depended-on libraries.

1. Generate project files with CMake
2. Set the working directory to the root of the project
3. Run the `quad_tennis_love` project!

## Keybinds
* `Home`: Resets the camera's position & rotation
* `Tab`: Resets the model's position & rotation
  
<br/>

* `1`: Select racket #1 (under the P)
* `2`: Select racket #2 (under the I)
* `3`: Select racket #3 (under the N)
* `4`: Select racket #4 (under the H)
* `5`: Snap the camera and focus on the center of the scene

<br/>

* `U`: Scale model up
* `J`: Scale model down

<br/>

_The following controls' direction were decided relative to the default camera's position, because it was assumed that the user wouldn't orbit the camera much._
* `W`: Move model forward (along the X axis)
* `A`: Move model left (along the Y axis)
* `S`: Move model backward (along the X axis)
* `D`: Move model right (along the Y axis)

<br/>

* `q`: Rotate model forward (around the X axis)
* `e`: Rotate model backward (around the X axis)
* `w`: Rotate model left (around the Y axis)
* `s`: Rotate model right (around the Y axis)
* `a`: Rotate model clockwise (around the Z axis)
* `d`: Rotate model counter-clockwise (around the Z axis)

<br/>

_The following changes the world orientation (orbits the camera)._
* `Up Arrow`: Orbit up
* `Right Arrow`: Orbit right
* `Down Arrow`: Orbit down
* `Left Arrow`: Orbit left

<br/>

* `Keypad 7`: Move camera upward (along the Z direction)
* `Keypad 9`: Move camera downward
* `Keypad 8`: Move camera forward (along where it's looking)
* `Keypad 4`: Move camera left
* `Keypad 2`: Move camera backward (along where it's looking)
* `Keypad 6`: Move camera right

<br/>

* `Right Click` & `Horizontal Mouse`: Pan the camera (rotates it horizontally)
* `Middle Click` & `Vertical Mouse`: TIlt the camera (rotates it vertically)
* `Left Click` & `Mouse`: Moves the camera in and out of the scene (along where it's looking)

<br/>

* `P`: Renders the model as points
* `L`: Renders the model as lines
* `T`: Renders the model as filled triangles (i.e. polygons)
