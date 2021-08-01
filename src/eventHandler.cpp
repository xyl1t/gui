#include "eventHandler.hpp"

#include <iostream>
#include <cstring>


void EventHandler::Update() {
    _mouseXRel = 0;
    _mouseYRel = 0;
    
    for(int i = 0; i < SDL_NUM_SCANCODES; i++) {
        _prevKeys[i] = _keys[i];
    }
	_capturedEvents.clear();
	int index{-1};
    while (SDL_PollEvent(&_event)) {
        _capturedEvents.push_back(_event);

		if (_event.type == SDL_WINDOWEVENT)
		{
			if (_event.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				index = _capturedEvents.size() - 1;
				// std::cout << _event.window.data1 << std::endl;
				// std::cout << "Window Resized! " << _capturedEvents[index].window.data1 << std::endl;
				
			}
		}

        if (_event.type == SDL_MOUSEMOTION) {
            _mouseXRel = _event.motion.xrel;
            _mouseYRel = _event.motion.yrel;
        }
    }
    
	
	// if(index != -1) {
	// 	std::cout << "Window Resized! " << _capturedEvents[index].type << std::endl;
	// }
	
    _isLeftMouseDown = SDL_GetMouseState(&_mouseX, &_mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT);
    _isRightMouseDown = SDL_GetMouseState(&_mouseX, &_mouseY) & SDL_BUTTON(SDL_BUTTON_RIGHT);
    _isMiddleMouseDown = SDL_GetMouseState(&_mouseX, &_mouseY) & SDL_BUTTON(SDL_BUTTON_MIDDLE);
	
	// for (int i = 0; i < _capturedEvents.size(); i++) {
    //     if(_capturedEvents[i].type == SDL_WINDOWEVENT) {
	// 		if (_capturedEvents[i].window.event == SDL_WINDOWEVENT_RESIZED) 
	// 			std::cout << "Window Resized! " << _capturedEvents[i].type << std::endl;
	// 	}
    // }
}

bool EventHandler::IsKeyDown(int key) {
    return (_keys[key]);
}

bool EventHandler::IsKeyUp(int key) {
    return !(_keys[key]);
}

bool EventHandler::IsKeyPressed(int key) {
    return (!(bool)_prevKeys[key] && (bool)_keys[key]);
}


std::vector<std::reference_wrapper<const SDL_Event>> EventHandler::IsEvent(uint32_t eventType) {
	std::vector<std::reference_wrapper<const SDL_Event>> events;
	for (const auto& event : _capturedEvents) {
        if(event.type == eventType) {
            events.push_back(std::ref(event));
		}
    }
    
    return events;
}
