#pragma once

// These will be called after ImGui and OpenGL are initialized
class IOnInit
{
public:
	virtual ~IOnInit() = default;
	virtual void OnInit() = 0;
};