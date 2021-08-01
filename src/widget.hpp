#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <memory>
#include <utility>
#include <vector>
#include "cidr.hpp"

namespace gui {

enum class AnchorType {
	None	= 0b0000,
	Top		= 0b0001,
	Bottom	= 0b0010,
	Left	= 0b0100,
	Right	= 0b1000,
};
enum class DockingType {
	None	= 0b00000,
	Top		= 0b00001,
	Bottom	= 0b00010,
	Left	= 0b00100,
	Right	= 0b01000,
	Fill	= 0b10000,
};

class Widget {
protected:
	std::shared_ptr<Widget> parent;
	std::vector<std::shared_ptr<Widget>> children;
	
	/* PROPERTIES */
	
	int x;
	int y;
	int z; // NOTE: widget stacking 
	int width;
	int height;
	
	AnchorType anchor;
	DockingType dockingType;
	bool enabled{true};
	bool autoSize{false};
	bool isFocused;
	
public:
	
};

}

#endif