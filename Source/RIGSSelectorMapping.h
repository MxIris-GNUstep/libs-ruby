/* RIGSSelectorMapping.m - Managing mapping between Objective-C method 
   names and Rubyones

   $Id$

   Copyright (C) 2000 Free Software Foundation, Inc.
   
   Written by:  Nicola Pero <nicola@brainstorm.co.uk>
   Date: October 2000
   
   This file is part of the GNUstep Ruby Interface Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.
   
   You should have received a copy of the GNU Library General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA.
   */ 

#ifndef __RIGSSelectorMapping_h_GNUSTEP_RUBY_INCLUDE
#define __RIGSSelectorMapping_h_GNUSTEP_RUBY_INCLUDE

#include "ruby.h"
#undef _

#include <Foundation/NSObject.h>
#include <Foundation/NSString.h>
#include <Foundation/NSDebug.h>


@interface NSSelector : NSObject
{
  SEL _sel; /* ObjC selector */
}

// NSSelector methods
+ (id) selectorWithCString: (char *) selCString;
+ (id) selectorWithString: (NSString*) selString;
+ (id) selectorWithSEL: (SEL) sel;
- (id) initSelectorWithCString: (char *) selCString;
- (id) initSelectorWithString: (NSString*) selString;
- (id) initSelectorWithSEL: (SEL)sel;
- (SEL) getSEL;

@end

// Some conversion methods from Ruby names to ObjC selectors (SEL)
// They are not really realted to the NSSelector class but they fit well
// in there
NSString* SelectorStringFromRubyName (char *name, BOOL hasArgs);
SEL SelectorFromRubyName (char *name, BOOL hasArgs);
NSString* RubyNameFromSelector(SEL sel);
NSString* RubyNameFromSelectorString(NSString *name);

#endif /* __RIGSSelectorMapping_h_GNUSTEP_RUBY_INCLUDE */
