FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y openssh-server git 

RUN useradd -m player && echo "player:password" | chpasswd && mkdir /var/run/sshd && chmod 755 /var/run/sshd

RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config
RUN sed -i 's/#PasswordAuthentication yes/PasswordAuthentication yes/' /etc/ssh/sshd_config

COPY git_chall/ /home/player/git_gud 

RUN chown -R player:player /home/player/git_gud

EXPOSE 22

CMD ["/usr/sbin/sshd", "-D"]
