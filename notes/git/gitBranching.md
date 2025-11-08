---
layout: default
title: Branching in Git
---

### Branching in Git

## What Are Branches?

A branch in Git is a lightweight, movable pointer to a commit. Think of it as an independent line of development that allows you to work on features, fixes, or experiments without affecting the main codebase.

When you create a branch, Git creates a new pointer - it doesn't create a whole new copy of your files. This makes branching fast and efficient.

**Why Use Branches?**

- **Isolation**: Work on new features without disturbing stable code
- **Collaboration**: Multiple team members can work simultaneously on different features
- **Experimentation**: Try out ideas without risk to the main project
- **Organization**: Keep different types of work (features, bugs, releases) separate
- **Code Review**: Create branches for changes that need review before merging

## Creating Branches

### Method 1: Create and Switch Separately

```bash
# Create a new branch (but stay on current branch)
git branch feature-login

# Switch to the new branch
git checkout feature-login
# or with newer Git versions:
git switch feature-login
```

### Method 2: Create and Switch in One Command

```bash
# Create and switch in one step (older syntax)
git checkout -b feature-login

# Create and switch in one step (newer syntax, Git 2.23+)
git switch -c feature-login
```

### Creating a Branch from a Specific Commit

```bash
# Create branch from a specific commit hash
git branch bugfix-123 a1b2c3d

# Create and switch to branch from a commit
git checkout -b bugfix-123 a1b2c3d
```

**What Happens When You Create a Branch?**

When you create a branch, Git:
1. Creates a new pointer with the branch name
2. Points it to your current commit
3. Allows you to make new commits that only affect this branch

```
Before branching:
main: A -- B -- C (HEAD)

After "git branch feature-login":
main: A -- B -- C
                 \
    feature-login (HEAD)

After making commits on feature-login:
main: A -- B -- C
                 \
    feature-login: D -- E (HEAD)
```

## Switching Between Branches

### Using git checkout

```bash
# Switch to an existing branch
git checkout main
git checkout feature-login

# Switch to previous branch (like "cd -" in shell)
git checkout -
```

### Using git switch (Recommended for Git 2.23+)

The `git switch` command was introduced to make branch operations clearer:

```bash
# Switch to an existing branch
git switch main
git switch feature-login

# Switch to previous branch
git switch -

# Create and switch to new branch
git switch -c new-feature
```

**Important**: When switching branches, Git:
- Updates your working directory to match the branch's latest commit
- Changes what files you see in your project folder
- Moves the HEAD pointer to the new branch

**Before Switching**: Ensure your working directory is clean (committed or stashed) to avoid conflicts.

## Viewing Branches

### List Local Branches

```bash
# List all local branches (* marks current branch)
git branch

# List with last commit info
git branch -v

# List with upstream tracking info
git branch -vv
```

Example output:
```
* feature-login    a1b2c3d Add login form
  main             d4e5f6g Initial commit
  bugfix-header    g7h8i9j Fix header style
```

### List Remote Branches

```bash
# List only remote branches
git branch -r

# List both local and remote branches
git branch -a
```

### Filter Branches

```bash
# List branches containing specific commit
git branch --contains a1b2c3d

# List merged branches
git branch --merged

# List branches not yet merged
git branch --no-merged
```

## Deleting Branches

### Delete a Local Branch

```bash
# Safe delete (only if branch is fully merged)
git branch -d feature-login

# Force delete (even if not merged)
git branch -D experimental-feature
```

Git will prevent you from deleting a branch with unmerged changes unless you use `-D`:

```bash
$ git branch -d feature-login
error: The branch 'feature-login' is not fully merged.
If you are sure you want to delete it, run 'git branch -D feature-login'.
```

### Delete a Remote Branch

```bash
# Delete a branch on the remote repository
git push origin --delete feature-login

# Alternative syntax
git push origin :feature-login
```

### Clean Up Stale Remote Branches

After branches are deleted on the remote, clean up your local references:

```bash
# Remove remote-tracking branches that no longer exist on remote
git fetch --prune
# or
git remote prune origin
```

## Branch Naming Conventions

Good branch names make collaboration easier. Common conventions:

### Descriptive Prefixes

```bash
feature/user-authentication
feature/payment-integration

bugfix/header-alignment
bugfix/login-validation

hotfix/security-patch
hotfix/critical-crash

release/v1.2.0
release/2024-q1

experiment/new-algorithm
experiment/ui-redesign
```

### Best Practices

1. **Use lowercase and hyphens**: `feature-login` not `FeatureLogin`
2. **Be descriptive**: `fix-header-spacing` not `fix`
3. **Include ticket numbers**: `bugfix-123-fix-memory-leak`
4. **Keep them short but meaningful**: Balance brevity with clarity
5. **Avoid special characters**: Stick to letters, numbers, hyphens, and forward slashes

### Common Patterns

```bash
# Type/description
feature/shopping-cart
bugfix/payment-error

# Type/ticket/description
feature/JIRA-123-add-search
bugfix/GH-456-fix-crash

# Your-name/type/description (for team work)
john/feature/api-endpoint
sarah/bugfix/css-issue
```

## Common Branching Strategies

### Feature Branch Workflow

The most common pattern: one branch per feature.

```bash
# Start from main
git switch main
git pull origin main

# Create feature branch
git switch -c feature/user-profile

# Work and commit
git add .
git commit -m "Add user profile page"

# Push to remote
git push -u origin feature/user-profile

# After review and approval, merge to main
git switch main
git merge feature/user-profile
git push origin main

# Delete feature branch
git branch -d feature/user-profile
git push origin --delete feature/user-profile
```

**Structure**:
```
main: A -- B -- F (after merge)
               /
feature:  C -- D -- E
```

### Git Flow Strategy

A more structured approach with multiple long-lived branches:

**Branches**:
- `main`: Production-ready code
- `develop`: Integration branch for features
- `feature/*`: Individual features
- `release/*`: Release preparation
- `hotfix/*`: Emergency fixes

```bash
# Feature development
git switch develop
git switch -c feature/new-api
# Work on feature
git switch develop
git merge feature/new-api

# Release preparation
git switch -c release/v1.2.0
# Bug fixes and version bumps
git switch main
git merge release/v1.2.0
git switch develop
git merge release/v1.2.0

# Hotfix for production
git switch main
git switch -c hotfix/critical-bug
# Fix the bug
git switch main
git merge hotfix/critical-bug
git switch develop
git merge hotfix/critical-bug
```

**Structure**:
```
main:    A ----------- F -------- H (production)
          \           /          /
develop:   B -- C -- E --------- G
            \       /
feature:     D ----
```

### GitHub Flow (Simplified)

A simpler approach, popular for continuous deployment:

1. `main` branch is always deployable
2. Create descriptive branches from `main`
3. Push and open pull request
4. Discuss and review
5. Deploy for testing
6. Merge to `main`

```bash
git switch main
git switch -c add-feature
# Work and commit
git push -u origin add-feature
# Open Pull Request on GitHub
# After approval, merge via GitHub
git switch main
git pull origin main
```

### Trunk-Based Development

Keep branches short-lived (hours or a day maximum):

```bash
# Create small, focused branch
git switch -c quick-fix

# Make minimal changes and commit
git add .
git commit -m "Fix typo in header"

# Merge quickly (same day)
git switch main
git merge quick-fix
git branch -d quick-fix
```

## Understanding HEAD

HEAD is a special pointer that tells Git which branch (or commit) you're currently on.

### Normal HEAD (Attached)

Usually, HEAD points to a branch name:

```bash
$ cat .git/HEAD
ref: refs/heads/main
```

This means HEAD is "attached" to the `main` branch. When you commit, `main` moves forward with your new commit.

### Detached HEAD State

When HEAD points directly to a commit (not a branch):

```bash
# Checkout a specific commit
git checkout a1b2c3d

# Git warns you:
# You are in 'detached HEAD' state...
```

**Visualization**:
```
Normal (attached) HEAD:
HEAD -> main -> A -- B -- C

Detached HEAD:
main -> A -- B -- C
HEAD ----------- ^
```

### Working with Detached HEAD

```bash
# Look at old code
git checkout a1b2c3d
# Explore and test (read-only exploration)

# If you want to make changes
git switch -c new-branch-from-old-commit
# Now you can commit safely

# Or just return to a branch
git switch main
```

**Why Detached HEAD Happens**:
- Checking out a specific commit: `git checkout <commit-hash>`
- Checking out a tag: `git checkout v1.0.0`
- Using `git bisect` for debugging
- Checking out a remote branch without creating local branch

**Recovering Work from Detached HEAD**:

If you made commits in detached HEAD state:

```bash
# Find your commit (before it's garbage collected)
git reflog

# Create a branch from that commit
git branch recover-branch <commit-hash>
```

## Practical Branching Workflows

### Workflow 1: Adding a New Feature

```bash
# 1. Update main branch
git switch main
git pull origin main

# 2. Create feature branch
git switch -c feature/add-search

# 3. Work on feature (make multiple commits)
git add search.js
git commit -m "Add search functionality"

git add search.css
git commit -m "Style search bar"

# 4. Keep feature branch updated with main
git switch main
git pull origin main
git switch feature/add-search
git merge main  # or use rebase

# 5. Push feature branch
git push -u origin feature/add-search

# 6. After merge, clean up
git switch main
git pull origin main
git branch -d feature/add-search
```

### Workflow 2: Quick Bug Fix

```bash
# 1. Create fix branch from main
git switch main
git switch -c bugfix/fix-login-error

# 2. Fix the bug
git add login.js
git commit -m "Fix login validation error"

# 3. Push and create PR
git push -u origin bugfix/fix-login-error

# 4. After merge
git switch main
git pull origin main
git branch -d bugfix/fix-login-error
```

### Workflow 3: Experimenting Safely

```bash
# 1. Create experiment branch
git switch -c experiment/redesign-ui

# 2. Try your ideas
git commit -am "Try new layout"
git commit -am "Experiment with colors"

# 3a. If successful, merge it
git switch main
git merge experiment/redesign-ui

# 3b. If unsuccessful, just delete it
git switch main
git branch -D experiment/redesign-ui
# All your experiment commits disappear
```

### Workflow 4: Reviewing Someone's Branch

```bash
# 1. Fetch all branches
git fetch origin

# 2. Check out their branch
git switch -c feature-review origin/feature/their-feature

# 3. Test the code
npm test
npm start

# 4. Return to your branch
git switch main

# 5. Clean up
git branch -d feature-review
```

## Best Practices for Branch Management

### 1. Keep Branches Focused

```bash
# Good: Single purpose
git switch -c fix-header-spacing

# Bad: Multiple unrelated changes
git switch -c fix-bugs-and-add-features
```

### 2. Update Branches Regularly

Keep your feature branch in sync with main to avoid large conflicts:

```bash
# Regularly merge main into your feature branch
git switch feature/my-feature
git merge main
```

### 3. Delete Merged Branches

Clean up to keep your repository tidy:

```bash
# After merging, delete the branch
git branch -d feature/completed-feature
git push origin --delete feature/completed-feature
```

### 4. Use Descriptive Names

Your branch name should explain what it contains:

```bash
# Good
git switch -c feature/user-authentication
git switch -c bugfix/payment-form-validation

# Bad
git switch -c temp
git switch -c new-branch
git switch -c asdf
```

### 5. Commit Before Switching

Always commit or stash before switching branches:

```bash
# Option 1: Commit your work
git add .
git commit -m "WIP: partial implementation"

# Option 2: Stash your work
git stash
git switch other-branch
git switch -
git stash pop
```

### 6. Review Before Merging

Always review changes before merging:

```bash
# See what will be merged
git diff main..feature/my-feature

# See commits that will be merged
git log main..feature/my-feature
```

### 7. Protect Important Branches

On team projects, protect `main` and `develop`:
- Require pull requests
- Require code reviews
- Require passing tests
- Prevent force pushes

### 8. Use Branch Conventions

Agree on naming conventions with your team:

```bash
# Example team convention
feature/*    # New features
bugfix/*     # Bug fixes
hotfix/*     # Urgent production fixes
release/*    # Release preparation
docs/*       # Documentation updates
```

## Common Branching Mistakes to Avoid

### Mistake 1: Working Directly on Main

```bash
# Bad: Making changes directly on main
git switch main
git commit -am "Add new feature"

# Good: Use a feature branch
git switch -c feature/new-feature
git commit -am "Add new feature"
```

### Mistake 2: Not Updating Before Creating Branch

```bash
# Bad: Branch from outdated main
git switch -c feature/new-feature

# Good: Update first
git switch main
git pull origin main
git switch -c feature/new-feature
```

### Mistake 3: Forgetting to Switch Branches

```bash
# Check current branch before committing
git branch

# Or include branch in prompt
git config --global prompt.showBranch true
```

### Mistake 4: Leaving Too Many Stale Branches

```bash
# Regularly clean up merged branches
git branch --merged | grep -v "main" | xargs git branch -d

# Clean up remote tracking branches
git fetch --prune
```

## Summary

**Key Concepts**:
- Branches are lightweight pointers to commits
- Create branches for features, bugs, and experiments
- Use descriptive names following team conventions
- Keep branches focused and short-lived
- Update branches regularly to avoid conflicts
- Delete branches after merging

**Essential Commands**:
```bash
git branch <name>           # Create branch
git switch <name>           # Switch to branch
git switch -c <name>        # Create and switch
git branch -v               # List branches
git branch -d <name>        # Delete branch
git merge <branch>          # Merge branch
git push origin <branch>    # Push branch to remote
```

**Remember**: Branching is one of Git's most powerful features. Use branches liberally - they're cheap to create and make your development process much safer and more organized.

<hr>

[Up](README.md) -- [Previous](gitCommitting.md) -- [Next](gitMerging.md)
