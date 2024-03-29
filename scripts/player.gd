extends CharacterBody2D;

const SPEED = 300.0;
const JUMP_VELOCITY = -400.0;

@export var ANGULAR_SPEED = PI;

# Get the gravity from the project settings to be synced with RigidBody nodes.
var gravity = ProjectSettings.get_setting("physics/2d/default_gravity");

func _init():
	print('hello');

func _physics_process(delta):
	if not is_on_floor():
		velocity.y += gravity * delta;
	#rotation += ANGULAR_SPEED * delta;
	
	if Input.is_action_just_pressed("ui_accept") and is_on_floor():
		velocity.y = JUMP_VELOCITY;

	var direction = Input.get_axis("ui_left", "ui_right")
	if direction:
		velocity.x = direction * SPEED;
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED);

	move_and_slide();
