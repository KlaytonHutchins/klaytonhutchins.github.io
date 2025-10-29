---
layout: default
title: Docker Images
---

### What are Docker Images?

A Docker image is a read-only template that contains:
* Application code
* Runtime environment
* System tools and libraries
* Configuration files

Images are the building blocks of containers. When you run an image, it becomes a running container.

### Image Layers

Docker images are built in layers. Each layer represents an instruction in the Dockerfile:

```
Layer 5: Copy application code
Layer 4: Install app dependencies
Layer 3: Install Node.js
Layer 2: Install system packages
Layer 1: Base OS (e.g., Ubuntu)
```

**Benefits of layers:**
* **Caching** - Unchanged layers are reused, speeding up builds
* **Efficiency** - Multiple images can share common layers
* **Version control** - Each layer is versioned

### Working with Images

#### Listing Images

```bash
# List all images on your system
docker images

# Alternative command
docker image ls
```

Output shows:
* Repository name
* Tag (version)
* Image ID
* Size
* Creation date

#### Pulling Images

```bash
# Pull an image from Docker Hub
docker pull nginx

# Pull a specific version
docker pull nginx:1.21

# Pull from a specific registry
docker pull gcr.io/my-project/my-image
```

#### Searching for Images

```bash
# Search Docker Hub for images
docker search nginx

# Limit results
docker search --limit 5 nginx
```

#### Removing Images

```bash
# Remove an image by name
docker rmi nginx

# Remove an image by ID
docker rmi abc123def456

# Remove unused images
docker image prune

# Remove all unused images
docker image prune -a

# Force remove an image
docker rmi -f nginx
```

### Image Tags

Tags identify specific versions of an image:

```bash
# Format: repository:tag
nginx:latest       # Latest stable version
nginx:1.21         # Specific version
nginx:1.21-alpine  # Alpine Linux variant
```

**Common conventions:**
* `latest` - Most recent stable version
* `alpine` - Minimal Alpine Linux-based version
* Version numbers - Specific releases (e.g., `3.9`, `14.17.0`)

### Inspecting Images

```bash
# View detailed information about an image
docker inspect nginx

# View image history (layers)
docker history nginx
```

### Image Naming

Full image name format:
```
registry.domain.com:port/namespace/repository:tag
```

Examples:
```
nginx:latest                           # Docker Hub default
docker.io/library/nginx:latest         # Full Docker Hub path
gcr.io/project-id/my-app:v1.0         # Google Container Registry
myregistry.com:5000/team/app:latest    # Private registry
```

### Best Practices

* **Use official images** - Start with official base images from Docker Hub
* **Use specific tags** - Avoid `latest` in production
* **Keep images small** - Use Alpine variants when possible
* **Regular updates** - Keep base images updated for security
* **Clean up** - Remove unused images to save disk space

> ### Skill++
> The largest Docker images can be several gigabytes, while minimal Alpine-based images can be just 5MB!

<hr>

[Prev](dockerBasics.md) -- [Up](README.md) -- [Next](dockerContainers.md)
