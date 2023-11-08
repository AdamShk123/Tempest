extends Node2D

var player_scene : PackedScene = preload('res://scenes/player.tscn');
var player_instance : CharacterBody2D;

func _ready():
	player_instance = player_scene.instantiate();
	add_child(player_instance);
	player_instance.position = Vector2(100,10);

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass;
