//
//  ViewController.m
//  BasicIntegrationObjectiveC
//
//  Created by Sergey Yuryev on 18.06.2020.
//  Copyright © 2020 Alan AI. All rights reserved.
//

@import AlanSDK;
#import "ViewController.h"

@interface ViewController ()

/// Alan button
@property (nonatomic) AlanButton* button;

/// Alan text panel
@property (nonatomic) AlanText* text;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Setup Alan Button and Text panel
    [self setupAlan];
}

- (void)setupAlan {
    // Define project key
    AlanConfig* config = [[AlanConfig alloc] initWithKey:@"314203787ccd9370974f1bf6b6929c1b2e956eca572e1d8b807a3e2338fdd0dc/prod"];

    //  Init Alan button
    self.button = [[AlanButton alloc] initWithConfig:config];
    
    // Init Alan text panel
    self.text = [[AlanText alloc] initWithFrame:CGRectZero];
    
    // Add button and text to the view
    [self.button setTranslatesAutoresizingMaskIntoConstraints:NO];
    [self.view addSubview:self.button];
    [self.text setTranslatesAutoresizingMaskIntoConstraints:NO];
    [self.view addSubview:self.text];

    // Aling button and text on the view
    NSDictionary* views = @{@"button" : self.button, @"text" : self.text};
    NSArray* verticalButton = [NSLayoutConstraint constraintsWithVisualFormat:@"V:|-(>=0@299)-[button(64)]-40-|" options:0 metrics:nil views:views];
    NSArray* verticalText = [NSLayoutConstraint constraintsWithVisualFormat:@"V:|-(>=0@299)-[text(64)]-40-|" options:0 metrics:nil views:views];
    NSArray* horizontalButton = [NSLayoutConstraint constraintsWithVisualFormat:@"H:|-(>=0@299)-[button(64)]-20-|" options:0 metrics:nil views:views];
    NSArray* horizontalText = [NSLayoutConstraint constraintsWithVisualFormat:@"H:|-20-[text]-20-|" options:0 metrics:nil views:views];
    [self.view addConstraints:verticalButton];
    [self.view addConstraints:verticalText];
    [self.view addConstraints:horizontalButton];
    [self.view addConstraints:horizontalText];
}


@end
