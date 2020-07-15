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

intent(`List all available items`, p => {
    let items = p.visual.items;
    if (Array.isArray(items)) {
        p.play(`There are items on this screen`);
        for (let i = 0; i < items.length; i++) {
            let item = items[i];
            p.play({command: 'highlight', item: item});
            p.play(`${item}`);
        } 
    }
    else {
        p.play(`There are no items on this screen`);
    } 
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


projectAPI.selectItem = function(p, param, callback) {
    if (!param || !param.item) {
        callback("error: item is undefined");
    }
    p.play(`This is detailed information about item ${param.item}`);
    callback();
};