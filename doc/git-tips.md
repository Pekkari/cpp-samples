# Bald Gorilla Git tips to ease branch revisions

## Tip one

Howdy... The Bald Gorilla has asked me to branch
this thing... how do I do it?

    * Be sure you are in the master branch.
```
$ git branch
```
    * Be sure you are updated.
```
$ git pull origin master
```
    * Branch it! It is now or never!
```
$ git checkout -b $MY_FLAWLESS_BRANCH_OF_CHOICE
```
    * Uffff was that it? Can anybody see it? No...
      Maybeeeee... I may need to push it back?
```
$ git push --set-upstream origin $$MY_FLAWLESS_BRANCH_OF_CHOICE
```
    * Yay! I see it! I see it! My browser shows it
      clearly! :D

## Tip two

Oh! No! A three-headed monkey have asked me to
do a branch revision... I have uncommited changes
in my git tree, and I'm in a different branch,
please help!

    * Stash your uncommited changes.
```
$ git stash
```
    * Check the name of the branch you need to review.
```
$ git branch -a
```
    * Check it out.
```
$ git checkout $BRANCH_NAME
```
    * Waw! Just one commit! Fantastic! :D.
```
$ git commit --amend
```
    * But wait, what was the tag I need to add?
      Reviewed-by: Name <email@address.com>

    * But hey, did I test it? Did I put the tests
      I did in place? perhaps I should amend twice...

    * Oh my... Looks fine but... how do I merge this thing?!?!
```
$ git pull --rebase origin master
$ git checkout master
$ git merge $BRANCH_NAME
$ git push
```
    * That is it? What about returning to my old work?
```
$ git checkout $YOUR_LOCAL_BRANCH
$ git stash apply
```
    * Keep rocking!

## Tip three

Oh my! The Three-headed Monkey wants me to review
multiple patches, god save me please!

    * Take a breath, calm down, no need to simulate
      a heart attack so that anybody else takes the
      review, I can do it!
    * Is this far different than tip 2? Looks like I
      Can use most of it, right? The problem may come
      when I want to modified older commits... how do
      I do this?
    * Look at the trouble.
```
$ git log
```
    * Copy the first hash before the new changes in the
      branch, git hints it with some text hinting it's
      the head of the master.
```
$ git rebase -i $COMMIT_HASH
```
    * Hey! it opened me a rare editor, what do I do know?
      Look the first line writes something like

```
pick $COMMIT_TITLE $COMMIT_HASH
```
    * What if I change pick word with edit in all the
      commits for review and save? Cool! git log now
      says I'm in the first commit to edit! :D
```
$ git commit --amend
```
    * But know, how do I get to next commit?
```
$ git rebase --continue
$ git commit --amend
```
    * Oh! I got to the last one, all have the tags, and
      the tests... Fantastic! We are almost there, right?
      Perhaps if I review the Tip 2 I can get it done! :D

