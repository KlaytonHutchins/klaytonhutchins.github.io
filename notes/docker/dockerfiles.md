---
layout: default
title: Dockerfiles
---

### What is a Dockerfile?

A Dockerfile is a text file containing instructions for building a Docker image. Each instruction creates a layer in the image.

### Basic Structure

```dockerfile
# Comments start with #
FROM base-image
RUN command
COPY source destination
CMD ["executable", "param1", "param2"]
```

### Common Instructions

#### FROM

Specifies the base image. Every Dockerfile must start with `FROM`.

```dockerfile
# Use official Node.js image
FROM node:16

# Use specific version
FROM ubuntu:20.04

# Use Alpine variant (smaller)
FROM node:16-alpine

# Multi-stage build
FROM node:16 AS builder
```

#### WORKDIR

Sets the working directory for subsequent instructions.

```dockerfile
WORKDIR /app

# All following commands run in /app
COPY . .
RUN npm install
```

#### COPY

Copies files from host to container.

```dockerfile
# Copy single file
COPY package.json .

# Copy directory
COPY src/ /app/src/

# Copy with wildcard
COPY *.json /app/

# Copy everything
COPY . .
```

#### ADD

Similar to COPY but with extra features (auto-extract archives, download URLs).

```dockerfile
# Extract tar file
ADD archive.tar.gz /app/

# Download from URL
ADD https://example.com/file.txt /app/
```

**Best practice:** Prefer `COPY` unless you need ADD's special features.

#### RUN

Executes commands during image build.

```dockerfile
# Install packages
RUN apt-get update && apt-get install -y curl

# Run multiple commands
RUN npm install && \
    npm run build && \
    npm cache clean --force

# Set environment for this command
RUN NODE_ENV=production npm install
```

#### CMD

Provides default command when container starts. Only one CMD per Dockerfile.

```dockerfile
# Exec form (preferred)
CMD ["node", "server.js"]

# Shell form
CMD node server.js

# Provide parameters to ENTRYPOINT
CMD ["--port", "3000"]
```

#### ENTRYPOINT

Configures container to run as executable. Often used with CMD.

```dockerfile
# Exec form (preferred)
ENTRYPOINT ["node", "server.js"]

# Shell form
ENTRYPOINT node server.js

# Use with CMD
ENTRYPOINT ["node"]
CMD ["server.js"]
```

**CMD vs ENTRYPOINT:**
* `CMD` - Easily overridden by command-line arguments
* `ENTRYPOINT` - Main executable, harder to override
* Use both - ENTRYPOINT for executable, CMD for default params

#### ENV

Sets environment variables.

```dockerfile
# Single variable
ENV NODE_ENV=production

# Multiple variables
ENV NODE_ENV=production \
    PORT=3000 \
    API_KEY=abc123
```

#### EXPOSE

Documents which ports the container listens on.

```dockerfile
# Single port
EXPOSE 3000

# Multiple ports
EXPOSE 3000 8080

# Port with protocol
EXPOSE 53/udp
```

**Note:** `EXPOSE` is documentation only. Use `-p` when running container to actually publish ports.

#### VOLUME

Creates mount point for persistent data.

```dockerfile
# Single volume
VOLUME /data

# Multiple volumes
VOLUME ["/data", "/logs"]
```

#### ARG

Defines build-time variables.

```dockerfile
# Define argument with default
ARG NODE_VERSION=16

# Use argument
FROM node:${NODE_VERSION}

# Build with custom value:
# docker build --build-arg NODE_VERSION=18 .
```

#### LABEL

Adds metadata to image.

```dockerfile
LABEL version="1.0"
LABEL description="My application"
LABEL maintainer="dev@example.com"
```

### Example Dockerfiles

#### Node.js Application

```dockerfile
# Use Node.js base image
FROM node:16-alpine

# Set working directory
WORKDIR /app

# Copy package files
COPY package*.json ./

# Install dependencies
RUN npm ci --only=production

# Copy application code
COPY . .

# Expose port
EXPOSE 3000

# Set environment
ENV NODE_ENV=production

# Run application
CMD ["node", "server.js"]
```

#### Python Application

```dockerfile
FROM python:3.9-slim

WORKDIR /app

# Copy requirements first (for caching)
COPY requirements.txt .

# Install dependencies
RUN pip install --no-cache-dir -r requirements.txt

# Copy application
COPY . .

# Expose port
EXPOSE 5000

# Run application
CMD ["python", "app.py"]
```

#### Multi-Stage Build

```dockerfile
# Build stage
FROM node:16 AS builder

WORKDIR /app

COPY package*.json ./
RUN npm ci

COPY . .
RUN npm run build

# Production stage
FROM node:16-alpine

WORKDIR /app

COPY package*.json ./
RUN npm ci --only=production

# Copy built files from builder stage
COPY --from=builder /app/dist ./dist

EXPOSE 3000

CMD ["node", "dist/server.js"]
```

### Building Images from Dockerfile

```bash
# Build from Dockerfile in current directory
docker build -t my-app .

# Build with specific tag
docker build -t my-app:v1.0 .

# Build from different directory
docker build -t my-app /path/to/dockerfile/

# Build with specific Dockerfile
docker build -t my-app -f Dockerfile.prod .

# Build with build arguments
docker build --build-arg NODE_VERSION=18 -t my-app .

# Build without cache
docker build --no-cache -t my-app .
```

### Best Practices

#### Order Matters

Place instructions that change less frequently at the top:

```dockerfile
# Good: Dependencies change less than source code
FROM node:16
WORKDIR /app
COPY package*.json ./
RUN npm install
COPY . .

# Bad: Every code change invalidates npm install cache
FROM node:16
WORKDIR /app
COPY . .
RUN npm install
```

#### Minimize Layers

Combine related RUN commands:

```dockerfile
# Good: Single layer
RUN apt-get update && \
    apt-get install -y curl git && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Bad: Multiple layers
RUN apt-get update
RUN apt-get install -y curl
RUN apt-get install -y git
```

#### Use .dockerignore

Create `.dockerignore` file to exclude files from build context:

```
node_modules
npm-debug.log
.git
.env
*.md
.DS_Store
```

#### Use Specific Tags

```dockerfile
# Good: Specific version
FROM node:16.14.0-alpine

# Avoid: May break builds
FROM node:latest
```

#### Don't Run as Root

```dockerfile
# Create non-root user
RUN useradd -m appuser

# Switch to non-root user
USER appuser

CMD ["node", "server.js"]
```

#### Keep Images Small

* Use Alpine base images
* Remove unnecessary files
* Use multi-stage builds
* Minimize number of layers

> ### Skill++
> The smallest possible Docker image is "scratch" - an empty base image that's literally zero bytes!

<hr>

[Prev](dockerContainers.md) -- [Up](README.md) -- [Next](dockerCompose.md)
