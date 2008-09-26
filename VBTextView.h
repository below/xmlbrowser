//
//  VBTextView.h
//  XMLBrowser
//
//  Created by Alexander v. Below on 31.08.08.
//  Copyright 2008 AVB Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface VBTextView : NSTextView {
	IBOutlet NSButton * actionButton;
}
- (IBAction *) escapeQuotes:(id)sender;
- (IBAction *) unescapeQuotes:(id)sender;

@end
