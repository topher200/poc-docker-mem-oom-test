FROM ubuntu:latest

WORKDIR /app

COPY mem.c /app

RUN apt-get update && \
    apt-get install -y build-essential && \ 
    gcc /app/mem.c -o /app/mem.out

ENTRYPOINT [ "/app/mem.out" ]
