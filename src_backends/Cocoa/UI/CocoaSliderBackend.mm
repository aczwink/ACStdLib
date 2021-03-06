/*
 * Copyright (c) 2018 Amir Czwink (amir130@hotmail.de)
 *
 * This file is part of Std++.
 *
 * Std++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Std++ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Std++.  If not, see <http://www.gnu.org/licenses/>.
 */
//Class header
#import "CocoaSliderBackend.hh"
//Local
#include <Std++/UI/Controls/Slider.hpp>
#import <Std++/UI/Events/ValueChangedEvent.hpp>
//Namespaces
using namespace _stdxx_;
using namespace StdXX;
using namespace StdXX::UI;

//Objective-C class
@implementation CocoaSlider
{
	CocoaSliderBackend *backend;
}

- (id)initWithBackend:(CocoaSliderBackend *)sliderBackend
{
	self = [super init];
	if(!self)
		return nil;
	self->backend = sliderBackend;
	return self;
}

- (void)OnValueChanged:(NSSlider *)sender
{
	self->backend->ValueChanged();
}
@end

//Constructor
CocoaSliderBackend::CocoaSliderBackend(UIBackend& uiBackend, Slider *slider) : SliderBackend(uiBackend), CocoaWidgetBackend(uiBackend), WidgetBackend(uiBackend), slider(slider)
{
	this->cocoaSlider = [[CocoaSlider alloc] initWithBackend:this];
	[this->cocoaSlider setTarget:this->cocoaSlider];
	[this->cocoaSlider setContinuous:YES];
	[this->cocoaSlider setAction:@selector(OnValueChanged:)];
}

//Destructor
CocoaSliderBackend::~CocoaSliderBackend()
{
	[this->cocoaSlider release];
}

//Public methods
Math::SizeD CocoaSliderBackend::GetSizeHint() const
{
	NSSize s = [this->cocoaSlider intrinsicContentSize]; //width is always -1
	return StdXX::Math::SizeD(0, s.height);
}

NSView *CocoaSliderBackend::GetView()
{
	return this->cocoaSlider;
}

Widget &CocoaSliderBackend::GetWidget()
{
	return *this->slider;
}

const Widget &CocoaSliderBackend::GetWidget() const
{
	return *this->slider;
}

void CocoaSliderBackend::SetEnabled(bool enable)
{
	[this->cocoaSlider setEnabled:enable];
}

void CocoaSliderBackend::SetPosition(uint32 pos)
{
	[this->cocoaSlider setIntValue:pos];
}

void CocoaSliderBackend::SetRange(uint32 min, uint32 max)
{
	[this->cocoaSlider setMinValue:min];
	[this->cocoaSlider setMaxValue:max];
}

void CocoaSliderBackend::ValueChanged()
{
	Variant value;
	value.i32 = [this->cocoaSlider intValue];

	ValueChangedEvent event(value);
	this->slider->Event(event);
}









//OLD STUFF
void CocoaSliderBackend::Repaint()
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}

void CocoaSliderBackend::SetEditable(bool enable) const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}