intent (`What is your name?`, p => {
    p.play(`It's Alan, and yours?`);
});

intent (`How are you doing?`, p => {
    p.play(`Good, thank you. What about you?`);
});

intent(`Navigate forward`, p => {
        p.play({command: 'navigation', route: 'forward'});
        p.play(`Navigating forward`);
});

intent(`Go back`, p => {
        p.play({command: 'navigation', route: 'back'});
        p.play(`Going back`);
});

intent(`What view is this?`, p => {
    let screen = p.visual.screen;
    switch (screen) {
        case "first":
            p.play(`This is the initial view`);           
            break;
		case "second":
            p.play(`This is the second view`);           
            break;
        default:
            p.play(`This is an example iOS app by Alan`);
    }      
});