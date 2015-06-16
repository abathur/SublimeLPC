# SublimeLPC
Sublime syntax highlighting support for LDMud / LPC (Lars Pensjö C)

    Note: only for ST3 Builds >= 3084

This is a working draft of Sublime Text 3 syntax highlighting for the LPC language, used to develop within LDMud. If you know what this project is for, I could use your help pushing it forwards. While the issue tracker (https://github.com/abathur/SublimeLPC/issues) will give you some idea of where to jump in, the most important tasks at the moment are:

1. identifying missing language features, edge cases in current matching, scopes that should be matched but aren't, scopes that need renaming, etc.
3. gathering feedback on the "Open" questions in the issue tracker
4. finishing out a robust, compiling syntax_test of the LPC language (see /test for a rough draft).

If you'd like to help develop SublimeLPC directly, you can:

1. remove any local copy of SublimeLPC (either through package control, or removing the directory if you cloned it)
2. fork this repo
3. `git clone` your fork into your ST3/Packages/ directory
4. create a new branch, edit, and submit a pull request

Any matching/scope changes should be accompanied by updates to the test cases (whether to just keep scopes in sync, add tests that match a bug or edge case, or introduce an example of a new feature.)

See http://www.sublimetext.com/docs/3/syntax.html for details on the syntax format.
