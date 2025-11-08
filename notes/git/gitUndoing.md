---
layout: default
title: Undoing Changes
---

### Undoing Changes

Git provides powerful tools to undo changes at various stages of your workflow. Understanding when and how to use each method is crucial for effective version control.

## Understanding Different Undo Scenarios

Before diving into specific commands, it's important to understand the three main states where you might need to undo changes:

1. **Working Directory**: Changes you've made but haven't staged
2. **Staging Area**: Changes you've added with `git add` but haven't committed
3. **Commit History**: Changes that have been committed to the repository

## Undoing Unstaged Changes

When you've modified files but haven't yet staged them, you can discard those changes.

### Using git restore (Modern Approach)

```bash
# Restore a specific file to its last committed state
git restore file.txt

# Restore all modified files in current directory
git restore .

# Restore all modified files in the repository
git restore :/
```

**What it does**: Discards changes in your working directory, reverting files to match the last commit.

### Using git checkout (Legacy Approach)

```bash
# Restore a specific file
git checkout -- file.txt

# Restore all files
git checkout -- .
```

**Note**: While `git checkout` still works, `git restore` is the newer, more focused command introduced in Git 2.23.

**WARNING**: These operations are destructive. Once you discard unstaged changes, they cannot be recovered.

## Unstaging Files

If you've staged changes but want to move them back to the working directory:

### Using git restore --staged (Modern Approach)

```bash
# Unstage a specific file
git restore --staged file.txt

# Unstage all files
git restore --staged .
```

**What it does**: Removes files from the staging area but preserves your changes in the working directory.

### Using git reset (Traditional Approach)

```bash
# Unstage a specific file
git reset HEAD file.txt

# Unstage all files
git reset HEAD
```

**Important**: Both methods keep your modifications intact; they only affect the staging area.

## Amending the Last Commit

Made a mistake in your most recent commit? You can fix it without creating a new commit.

```bash
# Change the commit message
git commit --amend -m "New commit message"

# Add forgotten files to the last commit
git add forgotten-file.txt
git commit --amend --no-edit

# Modify files and update the commit
git add modified-file.txt
git commit --amend
```

**What it does**: Replaces the last commit entirely with a new commit that includes your staged changes.

**When to use**:
- Fixing typos in commit messages
- Adding files you forgot to include
- Making small corrections before pushing

**WARNING**: Never amend commits that have been pushed to a shared branch, as this rewrites history and can cause problems for collaborators.

## Reverting Commits

When you need to undo a commit that's already been pushed or shared:

```bash
# Revert the most recent commit
git revert HEAD

# Revert a specific commit
git revert abc123

# Revert multiple commits
git revert HEAD~3..HEAD

# Revert without creating a commit immediately
git revert --no-commit abc123
```

**What it does**: Creates a new commit that undoes the changes introduced by the specified commit(s).

**Key characteristics**:
- Safe for shared branches
- Preserves history
- Creates a new commit showing what was undone
- Can be used on any commit, not just recent ones

**When to use**:
- Undoing commits on public/shared branches
- When you need to maintain a clear history of what was changed
- When working with team members

## Resetting Commits

Reset moves the current branch pointer to a different commit, effectively "uncommitting" changes.

### Reset Modes

#### Soft Reset
```bash
git reset --soft HEAD~1
```

**What it does**:
- Moves HEAD to the specified commit
- Keeps changes in the staging area
- Preserves your working directory

**Use case**: You want to recommit with a different message or combine commits.

**Visual representation**:
```
Before: A -- B -- C (HEAD)
After:  A -- B (HEAD)
        Changes from C are staged
```

#### Mixed Reset (Default)
```bash
git reset HEAD~1
# or
git reset --mixed HEAD~1
```

**What it does**:
- Moves HEAD to the specified commit
- Unstages changes (removes from staging area)
- Preserves your working directory

**Use case**: You want to redo the staging and commit process.

**Visual representation**:
```
Before: A -- B -- C (HEAD)
After:  A -- B (HEAD)
        Changes from C are in working directory (unstaged)
```

#### Hard Reset
```bash
git reset --hard HEAD~1
```

**What it does**:
- Moves HEAD to the specified commit
- Clears the staging area
- Discards all changes in your working directory

**Use case**: You want to completely discard commits and all changes.

**Visual representation**:
```
Before: A -- B -- C (HEAD)
After:  A -- B (HEAD)
        All changes from C are permanently deleted
```

**DANGER**: This is a destructive operation. All uncommitted changes and the specified commits will be lost.

### Reset Examples

```bash
# Undo the last commit, keep changes staged
git reset --soft HEAD~1

# Undo the last 3 commits, keep changes in working directory
git reset --mixed HEAD~3

# Reset to a specific commit, discard all changes
git reset --hard abc123

# Reset to match remote branch exactly
git reset --hard origin/main
```

## Revert vs Reset: When to Use Each

### Use Revert When:
- Working on a shared/public branch
- You need to maintain history
- The commit has already been pushed
- Collaborators have based work on the commit
- You want a clear audit trail

### Use Reset When:
- Working on a private/local branch
- The commit hasn't been pushed yet
- You want to clean up messy commit history before pushing
- You're the only one working on the branch

**Golden Rule**: If the commit has been pushed and others might have it, use `revert`. If it's only local, you can use `reset`.

## Recovering Lost Commits

If you accidentally reset or lose commits, Git's reflog can save you.

### Using git reflog

```bash
# View the reflog
git reflog

# Output example:
# abc123 HEAD@{0}: reset: moving to HEAD~1
# def456 HEAD@{1}: commit: Add feature
# ghi789 HEAD@{2}: commit: Fix bug
```

**What it shows**: A history of where HEAD has pointed, including "lost" commits.

### Recovering a Lost Commit

```bash
# Find the commit in reflog
git reflog

# Reset to the lost commit
git reset --hard def456

# Or create a new branch from the lost commit
git branch recovery-branch def456
```

**How it works**: Even after a hard reset, commits aren't immediately deleted. They remain in Git's object database and can be recovered using reflog references.

**Time limit**: Unreferenced commits are eventually garbage collected (usually after 30-90 days).

### Reflog for Specific Branches

```bash
# View reflog for a specific branch
git reflog show main

# View reflog with dates
git reflog show --date=relative
```

## Best Practices and Safety Tips

### Before Destructive Operations

1. **Check your status**:
   ```bash
   git status
   git log --oneline -5
   ```

2. **Create a backup branch**:
   ```bash
   git branch backup-branch
   ```

3. **Stash instead of discarding**:
   ```bash
   git stash  # Save changes temporarily
   git stash list  # View stashed changes
   git stash pop  # Restore stashed changes
   ```

### Safe Workflow Practices

1. **Use --no-edit with caution**: Always review what you're amending
2. **Avoid hard reset on shared branches**: Use revert instead
3. **Commit frequently**: Smaller commits are easier to undo
4. **Pull before reset**: Ensure you have the latest changes
5. **Test in a branch**: Try risky operations in a temporary branch first

### Quick Decision Guide

```
Need to undo changes?
|
├── Not committed yet?
|   ├── Not staged → git restore file.txt
|   └── Already staged → git restore --staged file.txt
|
├── Just committed (not pushed)?
|   ├── Small fix → git commit --amend
|   └── Wrong commit → git reset --soft HEAD~1
|
└── Already pushed?
    ├── Shared branch → git revert <commit>
    └── Private branch → git reset (if safe)
```

### Emergency Recovery

If something goes wrong:

1. **Don't panic**: Commits are rarely truly lost
2. **Check reflog**: `git reflog`
3. **Find your commit**: Look for the state before the problem
4. **Recover**: `git reset --hard <commit-hash>`
5. **Ask for help**: Share reflog output with experienced team members

## Common Scenarios

### Scenario 1: Wrong File in Commit
```bash
# Remove file from last commit but keep changes
git reset --soft HEAD~1
git restore --staged unwanted-file.txt
git commit -c ORIG_HEAD
```

### Scenario 2: Need to Split a Commit
```bash
# Undo last commit, keep changes unstaged
git reset HEAD~1
# Stage and commit files separately
git add file1.txt
git commit -m "First logical change"
git add file2.txt
git commit -m "Second logical change"
```

### Scenario 3: Accidentally Committed to Wrong Branch
```bash
# On wrong-branch
git reset --soft HEAD~1  # Undo commit, keep changes staged
git stash  # Save changes
git checkout correct-branch
git stash pop  # Apply changes
git commit -m "Commit message"
```

### Scenario 4: Recover Deleted Branch
```bash
# Find the commit where branch was deleted
git reflog
# Recreate branch
git branch recovered-branch <commit-hash>
```

## Summary

Undoing changes in Git is a powerful capability that requires understanding:

- **Restore/Checkout**: For discarding working directory changes
- **Restore --staged/Reset**: For unstaging files
- **Commit --amend**: For fixing the last commit
- **Revert**: For safely undoing public commits
- **Reset**: For rewriting local history
- **Reflog**: For recovering lost commits

Always prioritize safety: commit often, use branches for experiments, and prefer non-destructive operations when working with shared code. When in doubt, create a backup branch before performing any operation that modifies history.

<hr>

[Previous](gitRemotes.md) -- [Up](README.md) -- [Next](gitAdvanced.md)
