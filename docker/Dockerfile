FROM ubuntu:18.04

RUN apt-get update && apt-get install -y locales && apt-get install -y git &&  rm -rf /var/lib/apt/lists/* \
    && localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8
ENV LANG en_US.utf8

# Update aptitude with new repo
RUN apt-get update -y