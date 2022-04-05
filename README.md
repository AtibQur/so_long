# <h1 align="center"><a href="https://github.com/AtibQur/push_swap/blob/main/so_long.pdf" target="_blank">So_long 🎮  🕹️</a></h1>
<p><img align="right" src="./src/img/PNG_pictures/score.png" alt="Score" width="125" height="125"></p>
<h2>Description So_long</h2>
This project is all about creating a top down 2d game using the MLX library. The game reads a map which include a player(P), exit(E), collectables(C), walls(1), background(0) and an optional enemy(A). The goal is to create a game where collectables are collected before you can exit the game. In order to do this, your player character has to move over the collectable and collect the items.
<br><br>
<img src="./src/gif/so_long.gif" width="750" height="450" />
<h2>Rules</h2>
<li>The W, A, S, and D keys must be used to move the main character.</li> 
<li>The player should be able to move in these 4 directions: up, down, left, right.</li>
<li>The player should not be able to move into walls.</li>
<li>At every move, the current number of movements must be displayed in the shell.</li>
<li>Your program has to display the image in a window</li>
<li>The management of your window must remain smooth (changing to another window, minimizing, and so forth).</li>
<li>Pressing ESC must close the window and quit the program in a clean way.</li>
<li>Clicking on the cross on the window’s frame must close the window and quit the program in a clean way. </li>
<li>The map must be rectangular.</li>
<br>
<h2>Installation ⚙️</h2>
*To build the programm there is only a few steps: First of all, you can download the repository through the following steps in any shell of your preference:*
<br>
<pre>
git clone git@github.com:AtibQur/so_long.git
cd so_long
make
</pre>
These commands will compile everything and a executable <em>"so_long"</em> should be created. 
<br><br>
<h2>Usage 🛠️</h2>

<p>To compile the program, run the following command:</p>
<pre>
cd so_long && make
./so_long maps_valid_map.ber
</pre>
After creating the executable, the function is ready for use. This function only takes a map with an .ber extension.
<br></br>
<h2>Function explanation 📚</h2>
<table>
<li>initialize/start the game and give values to map variables.</li>
<li>parse/read through the map and do error managment for rectacle map, map variables, .ber extension. Give every position of the map it's own value(content).</li>
<li>read through the map and check if there's the required content items to start the game. give every content items it's own starting position. </li>
<li>give every node it's own image.</li>
<li>create the window and initialize the adress for every node img.</li>
<li>push every image to the window.</li>
<li>loop through every picture for the animation effect</li>
<li>create events for every key that is pressed</li>
<li>loops through the program and won't stop until ESC is pressed or force quit.</li>
</table>
<h2>Third-party helpers/testers</h2>
https://harm-smits.github.io/42docs/
<br>
https://eastmanreference.com/complete-list-of-applescript-key-codes
