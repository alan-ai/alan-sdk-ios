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
