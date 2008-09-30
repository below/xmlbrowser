//
//  XMLDocumentController.m
//  XMLBrowser
//
//  Created by Alexander v. Below on 26.09.08.
//  Copyright 2008 AVB Software. All rights reserved.
//

#import "XMLDocumentController.h"


@implementation XMLDocumentController
- (IBAction) openURI:(id)sender
{	
    [NSApp beginSheet: openURISheet
	   modalForWindow: nil
		modalDelegate: self
	   didEndSelector: @selector(didEndSheet:returnCode:contextInfo:)
		  contextInfo: nil];
}

- (IBAction) URIButtonAction:(id)sender
{
	[NSApp endSheet:openURISheet returnCode:[sender tag]];
}

- (void)didEndSheet:(NSWindow *)sheet returnCode:(int)returnCode contextInfo:(void *)contextInfo
{
	NSURL	* xmlURI;
	
    [sheet orderOut:self];
	switch (returnCode)
	{
		case 1:
				[self openDocumentWithContentsOfURL:xmlURI display:YES error:&error];
			break;
	}
}

- (NSString *)typeForContentsOfURL:(NSURL *)inAbsoluteURL error:(NSError **)outError
{	
	return [self typeFromFileExtension:[[inAbsoluteURL absoluteString] pathExtension] ];
}
@end
