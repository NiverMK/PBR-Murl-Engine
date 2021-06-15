#!/bin/bash

# *** Adapt the following variables *******************************

MURL_KEY_FILE="murl_release.keystore"
MURL_KEY_ALIAS=murl_key
MURL_KEY_PWD=

# *** Notice *** The following characters must be escaped if
# used as part of e.g. the password
#
# % escape with %%
# " escape with \"
# $ escape with \$
# \ escape with \\
# # embrace variable with double quotes
#
# *****************************************************************

if [ -z "$MURL_KEY_PWD" ]; then
  echo "*** Error *** No keystore password specified!"
  echo "Please specify a keystore password!"
  echo "Edit this script and add/modify the line: MURL_KEY_PWD=myPassword"
  exit 1
fi

echo "Starting keytool with:"
echo "- Alias: $MURL_KEY_ALIAS"
echo "- Password: $MURL_KEY_PWD"
echo ""

# keytool is part of the Java JRE / Java JDK. Ensure that your path variable has the java bin directory included.
keytool -genkey -v -keystore $MURL_KEY_FILE -alias $MURL_KEY_ALIAS -keyalg RSA -keysize 2048 -validity 10000 -storepass $MURL_KEY_PWD
if [ $? -gt 0 ]; then
  exit 1
else
  echo ""  
  echo "Warning: Keep the keystore file you generated in a safe, secure place."
  echo "You must use the same key to sign future versions of your application."
  echo "If you republish your app with a new key, Google Play will consider it as a new app."
  echo "For further information visit http://developer.android.com/tools/publishing/app-signing.html"
  echo "" 
fi

dir=$( cd "$( dirname "$0" )" && pwd )
echo "#!/bin/bash" > "${dir}/set_key_env.sh"
echo MURL_KEY_FILE="\"\$(pwd)/$MURL_KEY_FILE\"" >> "${dir}/set_key_env.sh"
echo MURL_KEY_ALIAS=$MURL_KEY_ALIAS >> "${dir}/set_key_env.sh"
echo MURL_KEY_PWD=$MURL_KEY_PWD >> "${dir}/set_key_env.sh"
chmod a+xrw "${dir}/set_key_env.sh"

echo set MURL_KEY_FILE="\"%~dp0$MURL_KEY_FILE\"" >> "${dir}/set_key_env.cmd"
echo set MURL_KEY_ALIAS=$MURL_KEY_ALIAS >> "${dir}/set_key_env.cmd"
echo set MURL_KEY_PWD=$MURL_KEY_PWD >> "${dir}/set_key_env.cmd"
