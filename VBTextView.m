//
//  VBTextView.m
//  XMLBrowser
//
//  Created by Alexander v. Below on 31.08.08.
//  Copyright 2008 AVB Software. All rights reserved.
//

#import "VBTextView.h"


@implementation VBTextView
- (void)keyDown:(NSEvent *)theEvent {
	if ([theEvent keyCode] != 0x4c) // Enter
		[super keyDown:theEvent];
	else
		[actionButton performClick:self];
}

#pragma mark Added by Alexander v. Below

- (IBAction) escapeQuotes:(id)sender
{
	NSMutableString * theString = [[[self string] mutableCopy] autorelease];
	
	[theString replaceOccurrencesOfString:@"\"" withString:@"\\\"" options:NSLiteralSearch range:NSMakeRange(0, [theString length])];
	[theString replaceOccurrencesOfString:@"\n" withString:@"\\n\\\n" options:NSLiteralSearch range:NSMakeRange(0, [theString length])];
	[self setString:theString];
}

- (IBAction) unescapeQuotes:(id)sender
{
	NSMutableString * theString = [[[self string] mutableCopy] autorelease];
	
	[theString replaceOccurrencesOfString:@"\\\"" withString:@"\"" options:NSLiteralSearch range:NSMakeRange(0, [theString length])];
	[theString replaceOccurrencesOfString:@"\\\n" withString:@"" options:NSLiteralSearch range:NSMakeRange(0, [theString length])];
	[theString replaceOccurrencesOfString:@"\\n" withString:@"\n" options:NSLiteralSearch range:NSMakeRange(0, [theString length])];
	
	[self setString:theString];
}
@end
