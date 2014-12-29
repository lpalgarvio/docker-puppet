###############################################################################
# Provisionous Docker/Puppet profile
# OS: Debian 6 (squeeze)
# Equivalent: Ubuntu 10.04 (lucid)
###############################################################################

FROM debian:squeeze
MAINTAINER Luís Pedro Algarvio <lp.algarvio@gmail.com>

# Configure the enviroment
ENV TERM linux
RUN export DEBIAN_FRONTEND="noninteractive";
WORKDIR /root

# Configure Apt
RUN echo "APT::Install-Recommends "\""false"\"";" >> /etc/apt/apt.conf;
RUN echo "APT::Install-Suggests "\""false"\"";" >> /etc/apt/apt.conf;

# Clear and Update the Apt cache
RUN ["/bin/bash", "-c", "if [ ! -f /var/lib/apt/lists/lock ]; then \
  apt-get clean all; apt-get update; fi;"]

# Install system dependencies
RUN apt-get -qqy install apt-utils dialog bash-completion wget nano;

# Configure /root profile
RUN cp -R /etc/skel/. /root;

# Upgrade the Apt packages
RUN apt-get -qqy upgrade;

# Build and deploy Ruby 1.9.3
# Source: http://wiki.itadmins.net/doku.php?id=debian:ruby1.9.3_on_squeeze
# Source: http://iomem.com/archives/18-Avoiding-tests-when-building-Debian-packages.html
#RUN apt-get -qqy install -t squeeze-backports \
#  build-essential devscripts debhelper fakeroot \
#  cdbs quilt autoconf m4 bison libgdbm-dev libncursesw5-dev libncurses5-dev \
#  libreadline6-dev tcl-dev tk-dev zlib1g-dev libssl-dev procps libffi-dev \
#  libyaml-dev openssl chrpath;
#RUN mkdir -p /root/packages;
#WORKDIR /root/packages
#RUN dget -u http://deb.bearstech.com/squeeze/ruby-1.9.3/ruby1.9.1_1.9.3.194-5bearstech1.dsc;
#WORKDIR /root/packages/ruby1.9.1-1.9.3.194
#RUN dpkg-buildpackage -rfakeroot;
#WORKDIR /root/packages
#RUN dpkg --install libruby1.9.1_1.9.3.194-5bearstech1_amd64.deb;
#RUN dpkg --install ruby1.9.1_1.9.3.194-5bearstech1_amd64.deb;
#RUN dpkg --install ruby1.9.1-dev_1.9.3.194-5bearstech1_amd64.deb;
#WORKDIR /root

# Download and deploy Ruby 1.9.3
#RUN mkdir -p /root/packages;
#WORKDIR /root/packages
#RUN apt-get install -qqy libffi5 libgdbm3 libyaml-0-2 libc6-dev;
#RUN wget http://deb.bearstech.com/squeeze/ruby-1.9.3/libruby1.9.1_1.9.3.392-bearstech1_amd64.deb;
#RUN wget http://deb.bearstech.com/squeeze/ruby-1.9.3/ruby1.9.1_1.9.3.392-bearstech1_amd64.deb;
#RUN wget http://deb.bearstech.com/squeeze/ruby-1.9.3/ruby1.9.1-dev_1.9.3.392-bearstech1_amd64.deb;
#RUN dpkg --install libruby1.9.1_1.9.3.392-bearstech1_amd64.deb;
#RUN dpkg --install ruby1.9.1_1.9.3.392-bearstech1_amd64.deb;
#RUN dpkg --install ruby1.9.1-dev_1.9.3.392-bearstech1_amd64.deb;
#WORKDIR /root

# Install Ruby 1.9.3 (from bearstech)
RUN mkdir -p /root/packages;
WORKDIR /root/packages
RUN echo "deb http://deb.bearstech.com/debian squeeze-bearstech main" > /etc/apt/sources.list.d/bearstech.list;
RUN wget -qO - http://deb.bearstech.com/bearstech-archive.gpg | apt-key add -;
RUN gpg --keyserver keys.gnupg.net --recv-keys 90158EE0;
RUN apt-get update;
RUN apt-get install -qqy ruby1.9.3 ruby1.9.1-dev rubygems-integration;
WORKDIR /root

# Configure Rubygems
RUN echo "gem: --no-ri --no-rdoc" > ~/.gemrc;

# Install Puppet
RUN apt-get -qqy install puppet;

# Install system dependencies
RUN apt-get -qqy install make gcc;

# Install Librarian for Puppet
RUN gem install librarian-puppet;

