---
layout: default
title: Advanced Git Features
---

### Advanced Git Features

This guide covers advanced Git features that enhance your workflow and provide powerful tools for complex version control scenarios.

#### 1. Rebasing (git rebase)

Rebasing is the process of moving or combining a sequence of commits to a new base commit. It rewrites commit history to create a linear progression.

**Basic Rebase:**
```bash
git checkout feature-branch
git rebase main
```

This moves your feature branch commits to start from the latest main branch commit.

**Interactive Rebase:**

Interactive rebase allows you to modify commits during the rebase process:

```bash
git rebase -i HEAD~3  # Rebase the last 3 commits
git rebase -i main    # Rebase onto main interactively
```

In interactive mode, you can:
- **pick**: Keep the commit as is
- **reword**: Change the commit message
- **edit**: Amend the commit
- **squash**: Combine with previous commit
- **fixup**: Like squash, but discard the commit message
- **drop**: Remove the commit
- **reorder**: Change commit order by moving lines

**Rebase vs Merge:**

| Rebase | Merge |
|--------|-------|
| Creates linear history | Preserves complete history |
| Rewrites commit history | Creates merge commits |
| Cleaner, easier to follow | Shows true branching structure |
| Never use on public branches | Safe for public branches |

**When to Use Each:**

**Use Rebase:**
- On local feature branches before merging
- To keep feature branches up to date with main
- To clean up commit history before sharing
- When you want a linear project history

**Use Merge:**
- For integrating completed features
- On public/shared branches
- When you want to preserve context
- For pull request workflows

**Warning:** Never rebase commits that have been pushed to a public repository and that others might have based work on.

#### 2. Stashing Changes (git stash)

Git stash temporarily shelves changes so you can work on something else, then come back and re-apply them later.

**Creating Stashes:**

```bash
git stash              # Stash tracked files
git stash -u           # Stash tracked and untracked files
git stash -a           # Stash all files (including ignored)
git stash save "message"  # Stash with a descriptive message
git stash push -m "message" path/to/file  # Stash specific files
```

**Applying Stashes:**

```bash
git stash pop          # Apply most recent stash and remove it
git stash apply        # Apply most recent stash and keep it
git stash apply stash@{2}  # Apply a specific stash
```

**Managing Stash List:**

```bash
git stash list         # Show all stashes
git stash show         # Show summary of latest stash
git stash show -p      # Show full diff of latest stash
git stash show stash@{1}  # Show specific stash
git stash drop stash@{1}  # Delete a specific stash
git stash clear        # Delete all stashes
```

**Use Cases:**
- Switch branches with uncommitted changes
- Pull latest changes without committing current work
- Temporarily test something without losing work
- Apply the same changes to multiple branches

#### 3. Cherry-Picking Commits (git cherry-pick)

Cherry-pick applies changes from specific commits to your current branch.

```bash
git cherry-pick <commit-hash>        # Apply single commit
git cherry-pick <hash1> <hash2>      # Apply multiple commits
git cherry-pick <hash1>..<hash3>     # Apply range of commits
git cherry-pick --no-commit <hash>   # Apply without committing
```

**Handling Conflicts:**

```bash
# If conflicts occur:
git cherry-pick --continue  # After resolving conflicts
git cherry-pick --abort     # Cancel the cherry-pick
git cherry-pick --skip      # Skip current commit
```

**Use Cases:**
- Apply a bug fix from one branch to another
- Port features to different versions
- Recover specific commits from abandoned branches
- Apply hotfixes to multiple release branches

**Best Practice:** Use cherry-pick sparingly. It duplicates commits and can complicate history. Consider merging when possible.

#### 4. Tagging (git tag)

Tags mark specific points in history as important, typically for releases.

**Lightweight Tags:**

Simple pointers to a commit:

```bash
git tag v1.0.0                    # Tag current commit
git tag v1.0.0 <commit-hash>      # Tag specific commit
```

**Annotated Tags:**

Full objects with tagger name, email, date, and message (recommended):

```bash
git tag -a v1.0.0 -m "Release version 1.0.0"
git tag -a v1.0.0 <commit-hash> -m "Release 1.0.0"
```

**Viewing Tags:**

```bash
git tag                # List all tags
git tag -l "v1.*"      # List tags matching pattern
git show v1.0.0        # Show tag details and commit
```

**Pushing Tags:**

Tags are not pushed by default:

```bash
git push origin v1.0.0      # Push single tag
git push origin --tags      # Push all tags
git push --follow-tags      # Push annotated tags with commits
```

**Deleting Tags:**

```bash
git tag -d v1.0.0                    # Delete local tag
git push origin --delete v1.0.0     # Delete remote tag
```

**Best Practices:**
- Use annotated tags for releases
- Follow semantic versioning (v1.2.3)
- Sign important tags with GPG
- Document release notes in tag messages

#### 5. Git Aliases for Productivity

Aliases create shortcuts for frequently used commands.

**Creating Aliases:**

```bash
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.st status
```

**Useful Aliases:**

```bash
# Pretty log
git config --global alias.lg "log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"

# Show last commit
git config --global alias.last "log -1 HEAD"

# Unstage files
git config --global alias.unstage "reset HEAD --"

# Amend without editing message
git config --global alias.amend "commit --amend --no-edit"

# List aliases
git config --global alias.aliases "config --get-regexp ^alias\."

# Undo last commit but keep changes
git config --global alias.undo "reset --soft HEAD^"

# Show branches sorted by last modified
git config --global alias.recent "branch --sort=-committerdate"
```

**Complex Aliases:**

```bash
# Delete merged branches
git config --global alias.cleanup "!git branch --merged | grep -v '\\*\\|main\\|master' | xargs -n 1 git branch -d"

# Commit with current branch name
git config --global alias.cob "!f() { git commit -m \"[\$(git symbolic-ref --short HEAD)] \$@\"; }; f"
```

#### 6. Searching in Git

Git provides powerful search capabilities across your repository's history.

**git grep - Search Working Directory:**

Search for text in tracked files:

```bash
git grep "search term"                    # Search in working directory
git grep "search term" HEAD~3             # Search in specific commit
git grep -n "search term"                 # Show line numbers
git grep -c "search term"                 # Show count per file
git grep -i "search term"                 # Case insensitive
git grep -w "search term"                 # Match whole words
git grep "search term" -- "*.js"          # Search specific file types
git grep -e "term1" --and -e "term2"      # Multiple patterns
```

**git log -S - Search Commit History (Pickaxe):**

Find commits that added or removed specific text:

```bash
git log -S "function_name"                # Find when string was added/removed
git log -S "function_name" --patch        # Show the actual changes
git log -S "function_name" -- path/to/file  # Search in specific file
git log -G "regex pattern"                # Search with regex
```

**Other Useful Searches:**

```bash
git log --grep="bug fix"              # Search commit messages
git log --author="John"               # Search by author
git log --since="2 weeks ago"         # Search by date
git log --all --source -- path/file   # Find which branch has a file
```

**Use Cases:**
- Find where a function was defined or removed
- Track when a bug was introduced
- Locate configuration changes
- Find commits related to specific features

#### 7. Bisect for Finding Bugs (git bisect)

Binary search through commit history to find which commit introduced a bug.

**Basic Workflow:**

```bash
# Start bisecting
git bisect start

# Mark current commit as bad
git bisect bad

# Mark a known good commit
git bisect good v1.0.0

# Git checks out a commit halfway between
# Test it, then mark as good or bad:
git bisect good    # If the commit is good
git bisect bad     # If the commit has the bug

# Repeat until Git finds the first bad commit

# End the bisect session
git bisect reset
```

**Automated Bisect:**

Run a test script automatically:

```bash
git bisect start HEAD v1.0.0
git bisect run npm test    # Or any command that exits 0 for good, 1 for bad
git bisect reset
```

**Advanced Options:**

```bash
git bisect skip              # Skip a commit (can't be tested)
git bisect visualize         # Visualize remaining commits
git bisect log               # Show bisect log
git bisect replay log.txt    # Replay bisect from log
```

**Use Cases:**
- Find regression bugs efficiently
- Identify performance degradation
- Locate when tests started failing
- Debug complex issues with many commits

**Tips:**
- Ensure builds are reproducible
- Have reliable tests
- Use automated bisect when possible
- Works best with small, focused commits

#### 8. Submodules Basics

Submodules allow you to keep a Git repository as a subdirectory of another Git repository.

**Adding a Submodule:**

```bash
git submodule add https://github.com/user/repo.git path/to/submodule
git commit -m "Add submodule"
```

**Cloning a Repository with Submodules:**

```bash
git clone --recursive https://github.com/user/repo.git

# Or after cloning:
git submodule init
git submodule update
```

**Updating Submodules:**

```bash
git submodule update --remote           # Update to latest remote version
git submodule update --remote --merge   # Merge remote changes
cd path/to/submodule && git pull        # Update specific submodule
```

**Working with Submodules:**

```bash
git submodule status              # Check submodule status
git submodule foreach git pull    # Run command in all submodules
git diff --submodule              # Show submodule changes in diffs
```

**Removing a Submodule:**

```bash
git submodule deinit path/to/submodule
git rm path/to/submodule
rm -rf .git/modules/path/to/submodule
```

**Use Cases:**
- Include third-party libraries
- Share code between projects
- Manage large monorepos
- Keep dependencies version-controlled

**Considerations:**
- Adds complexity to workflow
- Collaborators must initialize submodules
- Consider alternatives like package managers
- Modern alternatives: Git subtree, package managers

#### 9. Git Hooks Overview

Git hooks are scripts that run automatically at specific points in Git's execution.

**Common Hooks:**

**Client-Side Hooks:**

- **pre-commit**: Runs before commit is created
  - Check code style
  - Run linters
  - Validate commit message format

- **prepare-commit-msg**: Runs before commit message editor
  - Auto-generate commit message template
  - Add branch name to commit

- **commit-msg**: Runs after commit message is entered
  - Validate commit message format
  - Enforce commit message conventions

- **post-commit**: Runs after commit is created
  - Send notifications
  - Trigger CI/CD

- **pre-push**: Runs before push
  - Run tests
  - Prevent pushing to protected branches
  - Check for sensitive data

**Server-Side Hooks:**

- **pre-receive**: Runs when receiving pushed commits
- **update**: Like pre-receive but per branch
- **post-receive**: Runs after push is accepted
  - Deploy code
  - Send notifications
  - Update issue trackers

**Setting Up Hooks:**

Hooks are located in `.git/hooks/` directory:

```bash
cd .git/hooks
# Create hook file (remove .sample extension)
vim pre-commit
chmod +x pre-commit
```

**Example pre-commit Hook:**

```bash
#!/bin/sh
# Run tests before commit
npm test
if [ $? -ne 0 ]; then
    echo "Tests failed. Commit aborted."
    exit 1
fi
```

**Example commit-msg Hook:**

```bash
#!/bin/sh
# Enforce commit message format
commit_msg=$(cat "$1")
if ! echo "$commit_msg" | grep -qE "^(feat|fix|docs|style|refactor|test|chore):"; then
    echo "Error: Commit message must start with type (feat|fix|docs|etc)"
    exit 1
fi
```

**Managing Hooks in Teams:**

Since `.git/hooks` is not tracked, share hooks via:

1. **Scripts in repository:**
   ```bash
   # Store hooks in .githooks/
   git config core.hooksPath .githooks
   ```

2. **Tools like Husky (JavaScript):**
   - Automatically manages Git hooks
   - Stored in package.json
   - Easy to share across team

3. **Template directories:**
   ```bash
   git config --global init.templatedir ~/.git-templates
   ```

**Best Practices:**
- Keep hooks fast
- Make them optional for development
- Document hook requirements
- Provide bypass option when needed (`git commit --no-verify`)
- Test hooks thoroughly
- Use version control for hook scripts

<hr>

[Previous](gitUndoing.md) -- [Up](README.md) -- [Next](gitCommands.md)
