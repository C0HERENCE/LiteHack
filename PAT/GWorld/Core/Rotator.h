#pragma once
struct FRotator
{
public:
	/** Rotation around the right axis (around Y axis), Looking up and down (0=Straight Ahead, +Up, -Down) */
	float Pitch;

	/** Rotation around the up axis (around Z axis), Running in circles 0=East, +North, -South. */
	float Yaw;

	/** Rotation around the forward axis (around X axis), Tilting your head, 0=Straight, +Clockwise, -CCW. */
	float Roll;
};