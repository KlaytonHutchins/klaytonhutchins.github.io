---
layout: default
title: Common Git Commands
---

### Common Git Commands

This reference guide covers the most frequently used Git commands organized by category for quick lookup.

---

## 1. Configuration

### git config
Configure Git settings at global, system, or repository level.

**Syntax:**
```bash
git config [--global|--system|--local] <key> <value>
```

**Common Options:**
- `--global` - Apply to all repositories for the current user
- `--local` - Apply to current repository only (default)
- `--system` - Apply system-wide for all users
- `--list` - List all configuration settings
- `--unset` - Remove a configuration value

**Examples:**
```bash
# Set user information
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"

# Set default editor
git config --global core.editor "vim"

# Enable color output
git config --global color.ui auto

# List all settings
git config --list

# View specific setting
git config user.name
```

---

## 2. Repository Creation & Cloning

### git init
Create a new Git repository.

**Syntax:**
```bash
git init [directory]
```

**Examples:**
```bash
# Initialize repository in current directory
git init

# Create and initialize new directory
git init my-project

# Initialize bare repository (for servers)
git init --bare
```

### git clone
Copy an existing repository.

**Syntax:**
```bash
git clone <repository-url> [directory]
```

**Common Options:**
- `--branch <name>` - Clone specific branch
- `--depth <n>` - Shallow clone with limited history
- `--single-branch` - Clone only one branch

**Examples:**
```bash
# Clone repository
git clone https://github.com/user/repo.git

# Clone to specific directory
git clone https://github.com/user/repo.git my-folder

# Clone specific branch
git clone --branch develop https://github.com/user/repo.git

# Shallow clone (last 10 commits)
git clone --depth 10 https://github.com/user/repo.git
```

---

## 3. Basic Workflow

### git status
Show working tree status.

**Syntax:**
```bash
git status [options]
```

**Common Options:**
- `-s` or `--short` - Compact output format
- `-b` or `--branch` - Show branch information

**Examples:**
```bash
# Full status
git status

# Short format
git status -s

# Show branch and tracking info
git status -sb
```

### git add
Add files to staging area.

**Syntax:**
```bash
git add <pathspec>
```

**Common Options:**
- `-A` or `--all` - Add all changes (new, modified, deleted)
- `-u` or `--update` - Add modified and deleted files only
- `-p` or `--patch` - Interactive staging
- `.` - Add all in current directory

**Examples:**
```bash
# Add specific file
git add filename.txt

# Add all files in directory
git add src/

# Add all changes
git add -A
git add .

# Interactive staging
git add -p

# Add files by pattern
git add *.js
```

### git commit
Record changes to repository.

**Syntax:**
```bash
git commit [options]
```

**Common Options:**
- `-m <message>` - Commit message inline
- `-a` or `--all` - Automatically stage modified/deleted files
- `--amend` - Modify the last commit
- `--no-edit` - Keep existing commit message (with --amend)
- `-v` or `--verbose` - Show diff in commit message editor

**Examples:**
```bash
# Commit with message
git commit -m "Add new feature"

# Commit all tracked changes
git commit -am "Update documentation"

# Amend last commit
git commit --amend -m "Updated commit message"

# Amend without changing message
git commit --amend --no-edit

# Multi-line commit message
git commit -m "Short summary" -m "Detailed description"
```

### git diff
Show changes between commits, working tree, etc.

**Syntax:**
```bash
git diff [options] [<commit>] [--] [<path>]
```

**Common Options:**
- `--staged` or `--cached` - Show staged changes
- `--name-only` - Show only file names
- `--stat` - Show statistics

**Examples:**
```bash
# Show unstaged changes
git diff

# Show staged changes
git diff --staged

# Compare commits
git diff HEAD~1 HEAD

# Compare branches
git diff main..feature-branch

# Show only filenames
git diff --name-only

# Statistics summary
git diff --stat
```

---

## 4. Branching

### git branch
List, create, or delete branches.

**Syntax:**
```bash
git branch [options] [branch-name]
```

**Common Options:**
- `-a` or `--all` - List all branches (local and remote)
- `-r` or `--remotes` - List remote branches
- `-d` or `--delete` - Delete branch (safe)
- `-D` - Force delete branch
- `-m` or `--move` - Rename branch
- `-v` or `--verbose` - Show last commit on each branch

**Examples:**
```bash
# List local branches
git branch

# List all branches
git branch -a

# Create new branch
git branch feature-name

# Delete merged branch
git branch -d old-feature

# Force delete branch
git branch -D experimental

# Rename branch
git branch -m old-name new-name

# Show last commit per branch
git branch -v
```

### git checkout
Switch branches or restore files.

**Syntax:**
```bash
git checkout <branch-or-commit>
git checkout [options] <file>
```

**Common Options:**
- `-b` - Create and switch to new branch
- `-` - Switch to previous branch
- `--track` - Set up tracking with remote branch

**Examples:**
```bash
# Switch to branch
git checkout main

# Create and switch to new branch
git checkout -b feature-name

# Switch to previous branch
git checkout -

# Checkout specific commit
git checkout a1b2c3d

# Restore file from last commit
git checkout -- filename.txt

# Create branch from specific commit
git checkout -b hotfix a1b2c3d
```

### git switch
Switch branches (modern alternative to checkout).

**Syntax:**
```bash
git switch <branch>
```

**Common Options:**
- `-c` or `--create` - Create and switch to new branch
- `-` - Switch to previous branch

**Examples:**
```bash
# Switch to branch
git switch main

# Create and switch to new branch
git switch -c feature-name

# Switch to previous branch
git switch -
```

---

## 5. Merging

### git merge
Join two or more development histories.

**Syntax:**
```bash
git merge <branch>
```

**Common Options:**
- `--no-ff` - Create merge commit even if fast-forward
- `--ff-only` - Refuse merge unless fast-forward
- `--squash` - Squash commits into one
- `--abort` - Abort merge in case of conflicts
- `-m <message>` - Set merge commit message

**Examples:**
```bash
# Merge branch into current branch
git merge feature-branch

# Merge with no fast-forward
git merge --no-ff feature-branch

# Squash merge
git merge --squash feature-branch

# Abort merge due to conflicts
git merge --abort

# Merge with custom message
git merge -m "Merge feature X" feature-branch
```

### git rebase
Reapply commits on top of another base.

**Syntax:**
```bash
git rebase <branch>
```

**Common Options:**
- `-i` or `--interactive` - Interactive rebase
- `--continue` - Continue after resolving conflicts
- `--abort` - Abort rebase
- `--skip` - Skip current commit

**Examples:**
```bash
# Rebase current branch onto main
git rebase main

# Interactive rebase (last 3 commits)
git rebase -i HEAD~3

# Continue after resolving conflicts
git rebase --continue

# Abort rebase
git rebase --abort
```

---

## 6. Remote Repositories

### git remote
Manage remote repository connections.

**Syntax:**
```bash
git remote [options] [name] [url]
```

**Common Options:**
- `-v` or `--verbose` - Show URLs
- `add` - Add remote repository
- `remove` or `rm` - Remove remote
- `rename` - Rename remote
- `set-url` - Change remote URL

**Examples:**
```bash
# List remotes
git remote

# Show remote URLs
git remote -v

# Add remote
git remote add origin https://github.com/user/repo.git

# Remove remote
git remote remove origin

# Rename remote
git remote rename origin upstream

# Change remote URL
git remote set-url origin https://github.com/user/new-repo.git
```

### git fetch
Download objects and refs from remote.

**Syntax:**
```bash
git fetch [remote] [branch]
```

**Common Options:**
- `--all` - Fetch all remotes
- `--prune` - Remove deleted remote branches
- `--tags` - Fetch all tags

**Examples:**
```bash
# Fetch from origin
git fetch origin

# Fetch all remotes
git fetch --all

# Fetch and prune
git fetch --prune

# Fetch specific branch
git fetch origin main

# Fetch with tags
git fetch --tags
```

### git pull
Fetch and integrate with another repository.

**Syntax:**
```bash
git pull [remote] [branch]
```

**Common Options:**
- `--rebase` - Rebase instead of merge
- `--no-rebase` - Merge (default)
- `--ff-only` - Only fast-forward

**Examples:**
```bash
# Pull from tracked branch
git pull

# Pull from specific remote/branch
git pull origin main

# Pull with rebase
git pull --rebase

# Pull only if fast-forward
git pull --ff-only
```

### git push
Update remote refs along with associated objects.

**Syntax:**
```bash
git push [remote] [branch]
```

**Common Options:**
- `-u` or `--set-upstream` - Set tracking relationship
- `--all` - Push all branches
- `--tags` - Push tags
- `--force` or `-f` - Force push (dangerous!)
- `--force-with-lease` - Safer force push
- `--delete` - Delete remote branch

**Examples:**
```bash
# Push to tracked branch
git push

# Push and set upstream
git push -u origin main

# Push specific branch
git push origin feature-branch

# Push all branches
git push --all

# Push tags
git push --tags

# Delete remote branch
git push origin --delete old-branch

# Force push (use cautiously!)
git push --force-with-lease
```

---

## 7. Viewing History

### git log
Show commit logs.

**Syntax:**
```bash
git log [options]
```

**Common Options:**
- `--oneline` - Compact one-line format
- `--graph` - ASCII graph of branch structure
- `--all` - Show all branches
- `-n <number>` - Limit number of commits
- `--since=<date>` - Show commits after date
- `--until=<date>` - Show commits before date
- `--author=<pattern>` - Filter by author
- `--grep=<pattern>` - Search commit messages
- `-p` or `--patch` - Show diff with each commit

**Examples:**
```bash
# Basic log
git log

# Compact format
git log --oneline

# Graph view
git log --oneline --graph --all

# Last 5 commits
git log -n 5

# Commits by author
git log --author="John"

# Commits in date range
git log --since="2 weeks ago" --until="1 day ago"

# Search commit messages
git log --grep="fix bug"

# Show changes
git log -p

# File history
git log -- filename.txt

# Pretty format
git log --pretty=format:"%h - %an, %ar : %s"
```

### git show
Show various types of objects.

**Syntax:**
```bash
git show [object]
```

**Examples:**
```bash
# Show last commit
git show

# Show specific commit
git show a1b2c3d

# Show file from commit
git show HEAD:filename.txt

# Show tag
git show v1.0.0
```

### git reflog
Show reference logs (history of HEAD).

**Syntax:**
```bash
git reflog [options]
```

**Examples:**
```bash
# Show reflog
git reflog

# Show last 10 entries
git reflog -n 10

# Recover from reflog
git reset --hard HEAD@{2}
```

---

## 8. Undoing Changes

### git restore
Restore working tree files (modern alternative).

**Syntax:**
```bash
git restore [options] <file>
```

**Common Options:**
- `--staged` - Unstage files
- `--source=<commit>` - Restore from specific commit

**Examples:**
```bash
# Discard changes in file
git restore filename.txt

# Unstage file
git restore --staged filename.txt

# Restore from specific commit
git restore --source=HEAD~1 filename.txt
```

### git reset
Reset current HEAD to specified state.

**Syntax:**
```bash
git reset [mode] [commit]
```

**Common Options:**
- `--soft` - Keep changes staged
- `--mixed` - Keep changes unstaged (default)
- `--hard` - Discard all changes

**Examples:**
```bash
# Unstage file
git reset filename.txt

# Undo last commit, keep changes
git reset --soft HEAD~1

# Undo last commit, unstage changes
git reset HEAD~1

# Discard last commit and changes
git reset --hard HEAD~1

# Reset to specific commit
git reset --hard a1b2c3d
```

### git revert
Create new commit that undoes previous commit.

**Syntax:**
```bash
git revert <commit>
```

**Common Options:**
- `--no-commit` - Revert without committing
- `-n` - Same as --no-commit

**Examples:**
```bash
# Revert last commit
git revert HEAD

# Revert specific commit
git revert a1b2c3d

# Revert without committing
git revert --no-commit HEAD
```

### git clean
Remove untracked files.

**Syntax:**
```bash
git clean [options]
```

**Common Options:**
- `-n` or `--dry-run` - Show what would be removed
- `-f` or `--force` - Actually remove files
- `-d` - Remove directories
- `-x` - Remove ignored files too
- `-i` - Interactive mode

**Examples:**
```bash
# Preview what will be removed
git clean -n

# Remove untracked files
git clean -f

# Remove untracked files and directories
git clean -fd

# Remove including ignored files
git clean -fdx
```

---

## 9. Advanced Commands

### git stash
Temporarily save changes.

**Syntax:**
```bash
git stash [options]
```

**Common Options:**
- `save <message>` - Stash with message
- `list` - List stashes
- `apply` - Apply stash without removing
- `pop` - Apply and remove stash
- `drop` - Remove stash
- `clear` - Remove all stashes
- `-u` or `--include-untracked` - Include untracked files

**Examples:**
```bash
# Stash changes
git stash

# Stash with message
git stash save "Work in progress"

# Stash including untracked files
git stash -u

# List stashes
git stash list

# Apply last stash
git stash apply

# Apply and remove last stash
git stash pop

# Apply specific stash
git stash apply stash@{1}

# Drop stash
git stash drop stash@{0}

# Clear all stashes
git stash clear
```

### git tag
Create, list, or delete tags.

**Syntax:**
```bash
git tag [options] [tag-name]
```

**Common Options:**
- `-a` - Create annotated tag
- `-m <message>` - Tag message
- `-d` - Delete tag
- `-l` or `--list` - List tags

**Examples:**
```bash
# List tags
git tag

# Create lightweight tag
git tag v1.0.0

# Create annotated tag
git tag -a v1.0.0 -m "Release version 1.0.0"

# Tag specific commit
git tag v1.0.0 a1b2c3d

# Delete tag
git tag -d v1.0.0

# Push tags to remote
git push origin v1.0.0
git push origin --tags
```

### git cherry-pick
Apply changes from specific commits.

**Syntax:**
```bash
git cherry-pick <commit>
```

**Common Options:**
- `--continue` - Continue after resolving conflicts
- `--abort` - Abort cherry-pick
- `-n` or `--no-commit` - Apply without committing

**Examples:**
```bash
# Cherry-pick commit
git cherry-pick a1b2c3d

# Cherry-pick range
git cherry-pick a1b2c3d..x9y8z7w

# Cherry-pick without committing
git cherry-pick -n a1b2c3d
```

### git bisect
Binary search to find problematic commit.

**Syntax:**
```bash
git bisect <subcommand>
```

**Examples:**
```bash
# Start bisect
git bisect start

# Mark current as bad
git bisect bad

# Mark commit as good
git bisect good a1b2c3d

# After testing each revision...
git bisect good  # or git bisect bad

# Finish bisect
git bisect reset
```

---

## 10. Useful Flags & Options

### Common Flags Across Commands

**Output Formatting:**
- `--oneline` - Compact single-line output
- `--stat` - Show statistics
- `--graph` - Show ASCII graph
- `-v` or `--verbose` - Detailed output
- `-q` or `--quiet` - Suppress output

**Filtering:**
- `-n <number>` - Limit output
- `--since=<date>` - After date
- `--until=<date>` - Before date
- `--author=<name>` - By author
- `--grep=<pattern>` - Search messages

**Safety:**
- `--dry-run` or `-n` - Show what would happen
- `--force` or `-f` - Force operation
- `--force-with-lease` - Safer force
- `-i` or `--interactive` - Interactive mode

### Git Aliases

Create shortcuts for frequently used commands:

```bash
# Create aliases
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.cm commit
git config --global alias.unstage 'reset HEAD --'
git config --global alias.last 'log -1 HEAD'
git config --global alias.visual 'log --oneline --graph --all'

# Use aliases
git st
git co main
git visual
```

### Help Commands

```bash
# General help
git help

# Command-specific help
git help commit
git commit --help

# Quick reference
git <command> -h
```

---

## Quick Reference Cheatsheet

**Setup:**
```bash
git config --global user.name "Name"
git config --global user.email "email@example.com"
```

**Create/Clone:**
```bash
git init
git clone <url>
```

**Basic Workflow:**
```bash
git status
git add <file>
git commit -m "message"
git push
git pull
```

**Branching:**
```bash
git branch <name>          # Create branch
git checkout <name>        # Switch branch
git merge <name>          # Merge branch
git branch -d <name>      # Delete branch
```

**Undo Changes:**
```bash
git restore <file>        # Discard changes
git reset --soft HEAD~1   # Undo commit, keep changes
git revert HEAD           # Create revert commit
```

**View History:**
```bash
git log --oneline --graph
git diff
git show <commit>
```

---

This reference covers the most essential Git commands. For detailed information on any command, use `git help <command>` or visit the [official Git documentation](https://git-scm.com/doc).

<hr>

[Up](README.md) -- [Previous](gitAdvanced.md)
