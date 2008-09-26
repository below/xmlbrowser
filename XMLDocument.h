//
//  XMLDocument.h
//  XMLBrowser
//
//  Created by Alexander v. Below on 25.09.08.
//  Copyright 2008 AVB Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface XMLDocument : NSDocument 
{	
    // The "Source" URL (Source tab)
    IBOutlet NSTextField *urlTextField;
		
    // A view of the source (Source tab)
    IBOutlet NSTextView *sourceTextView;    
	
    // A view of the current selected node (Editor tab)
    IBOutlet NSTextView *nodeTextView;    
	
    // The XML with modifications applied from the Browse tab (Result tab)
    IBOutlet NSTextView *resultTextView;
	
    // Where the user inputs their XQuery (XQuery tab)
    IBOutlet NSTextView *xquerySourceTextView;
	
    // The result of applying the XQuery to the current document (XQuery tab)
    IBOutlet NSTextView *xqueryResultTextView;
	
    // The set of tabs
    IBOutlet NSTabView *mainTabView;
	
    // The set of input and output options
    IBOutlet NSMatrix *fidelityMatrix;
	
    // Children of the current selected node
    IBOutlet NSTableView *childrenTableView;
	
    // Attributes of the current selected element
    IBOutlet NSTableView *attributeTableView;
	
    // Namespaces of the current selected element
    IBOutlet NSTableView *namespaceTableView;
	
    // Set of array controllers for the different array we may display
    IBOutlet NSArrayController *children;
    IBOutlet NSArrayController *attributes;
    IBOutlet NSArrayController *namespaces;
    IBOutlet NSArrayController *dtdNodes;
    
    // Sheet to display errors on parse, connect, or XQuery
    NSAlert *alertSheet;
    
    // The URL we read (for files: and write) to
    NSURL *url;
    
    // The data at the URL
    NSData *data;
    
	// The encoding of the data
	NSStringEncoding dataEncoding;
	
    // Document that results after parsing the data
    NSXMLDocument *document;
    
    // The set of options to use for input from the fidelityMatrix
    unsigned int options;
    
    // The current node (changes as the user moves up and down the tree)
    NSXMLNode *current;
}

- (IBAction)setSelectedTab:(id)sender;

- (IBAction)fetchAndDisplayURL:(id)sender;
- (IBAction)applyNSXML:(id)sender;
- (IBAction)applyXQuery:(id)sender;
- (IBAction)setResult:(id)sender;
- (IBAction)setFidelity:(id)sender;
- (IBAction)setCurrentToSelectedChildren:(id)sender;
- (IBAction)setCurrentToSelectedParent:(id)sender;
- (IBAction)addAttributeToCurrent:(id)sender;
- (IBAction)addNamespaceToCurrent:(id)sender;
- (IBAction)addChildToCurrent:(id)sender;

- (void)setData:(NSData *)theData encoding:(NSString *)encoding;
- (NSData *)data;
- (void)setURL:(NSURL *)theUrl;
- (NSURL *)url;
- (void)setDocument:(NSXMLDocument *)doc;
- (NSXMLDocument *)document;
- (void)setCurrent:(NSXMLNode *)theCurrent;
- (NSXMLNode *)current;

- (void)setSourceTextViewString:(NSString *)string;
- (void) updateSourceTextView;
- (void)setNodeTextViewString:(NSString *)string;
- (void)setXQuerySourceTextViewString:(NSString *)string;
- (void)setXQueryResultTextViewString:(NSString *)string;
- (void)setResultTextViewString:(NSString *)string;
@end
