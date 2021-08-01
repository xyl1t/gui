#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#if __has_include("SDL2/SDL.h")
# include <SDL2/SDL.h>
#else
# include <SDL.h>
#endif

#include <deque>
#include <vector>

namespace EventHandler {
    inline SDL_Event _event{};
    // input fields
    inline uint8_t _prevKeys[SDL_NUM_SCANCODES] { 0 };
    inline uint8_t* _keys{(uint8_t*)SDL_GetKeyboardState(nullptr)};
    inline int _mouseX{};
    inline int _mouseY{};
    inline int _mouseXRel{};
    inline int _mouseYRel{};
    inline int _isLeftMouseDown{};
    inline int _isRightMouseDown{};
    inline int _isMiddleMouseDown{};
    inline std::deque<SDL_Event> _capturedEvents{};
	
    void Update();
    
    bool IsKeyDown(int key);
    bool IsKeyUp(int key);
    bool IsKeyPressed(int key);
    inline int GetMouseX() {
        return _mouseX;
    }
    inline int GetMouseY() {
        return _mouseY;
    }
    inline int GetMouseXRel() {
        return _mouseXRel;
    }
    inline int GetMouseYRel() {
        return _mouseYRel;
    }
    inline bool IsLeftMouseDown() {
        return _isLeftMouseDown;
    }
    inline bool IsRightMouseDown() {
        return _isRightMouseDown;
    }
    //bool IsMiddleMouseDown();
	inline SDL_Event GetEvent() { return _event; }
	// inline uint32_t* GetEventType() { return _eventType; }
	
    std::vector<std::reference_wrapper<const SDL_Event>> IsEvent(uint32_t eventType);
};


#endif /* EVENTHANDLER_HPP */
