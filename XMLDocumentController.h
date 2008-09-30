//
//  XMLDocumentController.h
//  XMLBrowser
//
//  Created by Alexander v. Below on 26.09.08.
//  Copyright 2008 AVB Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface XMLDocumentController : NSDocumentController {
	IBOutlet NSWindow * openURISheet;
	IBOutlet NSTextField * openURITextField;
}
- (IBAction) openURI:(id)sender;
- (IBAction) URIButtonAction:(id)sender;

@end
