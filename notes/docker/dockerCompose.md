---
layout: default
title: Docker Compose
---

### What is Docker Compose?

Docker Compose is a tool for defining and running multi-container Docker applications. With Compose, you use a YAML file to configure your application's services, networks, and volumes.

### Why Use Docker Compose?

* **Multi-container orchestration** - Manage multiple containers as a single application
* **Simple configuration** - Define everything in a single `docker-compose.yml` file
* **Easy commands** - Start entire application stack with one command
* **Development environment** - Consistent environments across team members
* **Service dependencies** - Define startup order and dependencies

### Installation

Docker Compose comes bundled with Docker Desktop for Mac and Windows.

For Linux:
```bash
# Download Docker Compose
sudo curl -L "https://github.com/docker/compose/releases/latest/download/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose

# Make executable
sudo chmod +x /usr/local/bin/docker-compose

# Verify installation
docker-compose --version
```

### Basic docker-compose.yml

```yaml
version: '3.8'

services:
  web:
    image: nginx:latest
    ports:
      - "8080:80"

  api:
    image: node:16-alpine
    working_dir: /app
    volumes:
      - ./api:/app
    command: npm start
```

### YAML Structure

#### Version

Specifies the Compose file format version:

```yaml
version: '3.8'  # Use latest version compatible with your Docker
```

#### Services

Define containers to run:

```yaml
services:
  service-name:
    # Service configuration
```

### Service Configuration Options

#### Using an Image

```yaml
services:
  web:
    image: nginx:latest
```

#### Building from Dockerfile

```yaml
services:
  app:
    build: .

  # Or with more options
  api:
    build:
      context: ./api
      dockerfile: Dockerfile.dev
      args:
        NODE_VERSION: 16
```

#### Ports

```yaml
services:
  web:
    ports:
      - "8080:80"      # host:container
      - "443:443"
      - "3000-3005:3000-3005"  # Port range
```

#### Environment Variables

```yaml
services:
  db:
    environment:
      POSTGRES_USER: admin
      POSTGRES_PASSWORD: secret
      POSTGRES_DB: myapp

  # Or from file
  api:
    env_file:
      - .env
      - .env.prod
```

#### Volumes

```yaml
services:
  app:
    volumes:
      - ./src:/app/src        # Bind mount
      - node_modules:/app/node_modules  # Named volume
      - /app/logs             # Anonymous volume

# Define named volumes
volumes:
  node_modules:
```

#### Networks

```yaml
services:
  web:
    networks:
      - frontend

  api:
    networks:
      - frontend
      - backend

  db:
    networks:
      - backend

# Define networks
networks:
  frontend:
  backend:
```

#### Dependencies

```yaml
services:
  api:
    depends_on:
      - db
      - cache

  db:
    image: postgres:13

  cache:
    image: redis:6
```

#### Container Name

```yaml
services:
  web:
    container_name: my-web-server
```

#### Restart Policy

```yaml
services:
  app:
    restart: always  # no, always, on-failure, unless-stopped
```

#### Command

```yaml
services:
  app:
    command: npm run dev

  # Or as array
  worker:
    command: ["celery", "worker", "-A", "tasks"]
```

### Complete Example

```yaml
version: '3.8'

services:
  # Web Server
  nginx:
    image: nginx:alpine
    ports:
      - "80:80"
    volumes:
      - ./nginx.conf:/etc/nginx/nginx.conf
      - static_files:/usr/share/nginx/html
    depends_on:
      - api
    networks:
      - frontend
    restart: unless-stopped

  # API Server
  api:
    build:
      context: ./api
      dockerfile: Dockerfile
    environment:
      NODE_ENV: production
      DB_HOST: postgres
      REDIS_HOST: redis
    ports:
      - "3000:3000"
    volumes:
      - ./api:/app
      - /app/node_modules
    depends_on:
      - postgres
      - redis
    networks:
      - frontend
      - backend
    restart: unless-stopped

  # Database
  postgres:
    image: postgres:13-alpine
    environment:
      POSTGRES_USER: ${DB_USER}
      POSTGRES_PASSWORD: ${DB_PASSWORD}
      POSTGRES_DB: ${DB_NAME}
    volumes:
      - postgres_data:/var/lib/postgresql/data
    networks:
      - backend
    restart: unless-stopped

  # Cache
  redis:
    image: redis:6-alpine
    volumes:
      - redis_data:/data
    networks:
      - backend
    restart: unless-stopped

volumes:
  postgres_data:
  redis_data:
  static_files:

networks:
  frontend:
  backend:
```

### Docker Compose Commands

#### Starting Services

```bash
# Start all services
docker-compose up

# Start in detached mode (background)
docker-compose up -d

# Start specific service
docker-compose up web

# Build and start
docker-compose up --build

# Recreate containers
docker-compose up --force-recreate
```

#### Stopping Services

```bash
# Stop services
docker-compose stop

# Stop specific service
docker-compose stop web

# Stop and remove containers
docker-compose down

# Stop and remove containers, volumes, and images
docker-compose down -v --rmi all
```

#### Viewing Services

```bash
# List running services
docker-compose ps

# View service logs
docker-compose logs

# Follow logs
docker-compose logs -f

# Logs for specific service
docker-compose logs -f api

# View last 100 lines
docker-compose logs --tail=100
```

#### Executing Commands

```bash
# Execute command in running service
docker-compose exec api npm test

# Open shell in service
docker-compose exec api sh

# Run one-off command (starts new container)
docker-compose run api npm install
```

#### Building Images

```bash
# Build all services
docker-compose build

# Build specific service
docker-compose build api

# Build without cache
docker-compose build --no-cache
```

#### Scaling Services

```bash
# Scale service to multiple instances
docker-compose up -d --scale api=3

# Scale multiple services
docker-compose up -d --scale api=3 --scale worker=5
```

#### Other Commands

```bash
# Validate docker-compose.yml
docker-compose config

# View images used by services
docker-compose images

# Pause services
docker-compose pause

# Unpause services
docker-compose unpause

# Restart services
docker-compose restart

# Pull latest images
docker-compose pull
```

### Development Workflow Example

Project structure:
```
my-app/
├── docker-compose.yml
├── .env
├── api/
│   ├── Dockerfile
│   ├── package.json
│   └── src/
└── nginx/
    └── nginx.conf
```

docker-compose.yml:
```yaml
version: '3.8'

services:
  api:
    build: ./api
    volumes:
      - ./api:/app
      - /app/node_modules
    ports:
      - "3000:3000"
    environment:
      - NODE_ENV=development
    command: npm run dev
```

Workflow:
```bash
# Start development environment
docker-compose up

# Make code changes (auto-reloads with volume mount)

# View logs
docker-compose logs -f api

# Run tests
docker-compose exec api npm test

# Stop environment
docker-compose down
```

### Environment Variables

.env file:
```
DB_USER=admin
DB_PASSWORD=secret
DB_NAME=myapp
API_PORT=3000
```

Use in docker-compose.yml:
```yaml
services:
  db:
    environment:
      POSTGRES_USER: ${DB_USER}
      POSTGRES_PASSWORD: ${DB_PASSWORD}

  api:
    ports:
      - "${API_PORT}:3000"
```

### Best Practices

* **Use version control** - Commit docker-compose.yml, not .env
* **Environment-specific files** - Use docker-compose.override.yml for local development
* **Named volumes** - Use named volumes for data persistence
* **Health checks** - Add health checks for critical services
* **Resource limits** - Set memory and CPU limits in production
* **Separate networks** - Isolate services with different networks
* **Use secrets** - Don't hardcode passwords, use environment variables

### docker-compose.override.yml

Automatically merged with docker-compose.yml:

docker-compose.yml (production):
```yaml
version: '3.8'
services:
  api:
    image: myapp:latest
```

docker-compose.override.yml (development):
```yaml
version: '3.8'
services:
  api:
    build: ./api
    volumes:
      - ./api:/app
    command: npm run dev
```

> ### Skill++
> Docker Compose can manage applications with hundreds of services, though most applications use fewer than 10.

<hr>

[Prev](dockerfiles.md) -- [Up](README.md) -- [Next](dockerNetworking.md)
