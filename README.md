# SublimeLPC
Sublime syntax highlighting support for LDMud / LPC (Lars Pensjö C)

This is an early working draft of Sublime Text 3 syntax highlighting for the LPC language, used to develop within LDMud. I don't recommend anyone start basing themes on this yet (unless they're okay with repeating work.) If you know what this project is for, I could use your help pushing it forwards (especially when it comes to scope naming, where I have almost no experience and am staring down some significant decision fatigue.)

While you can see the TODO file in root for my current working notes if you'd like to help, the TLDR version is that I could use your help with a short list of things:

	1. naming scopes
	2. identifying missing language features or edge cases in current matching
	3. gathering feedback on the "Open" questions in the TODO
	4. filling out a robust, compiling test of the LPC language (see /test for work in progress), and (once scopes are mostly settled) converting it into an ST3 syntax test.

If you have any business installing this at this point, you should be able to figure out how to do so from the ST3 documentation. (In short, it should suffice to git clone this into your ST3/Packages/User/) directory, open up an LPC file, and select LPC, or User->LPC for your syntax.

See http://www.sublimetext.com/docs/3/syntax.html for details on the syntax format.
