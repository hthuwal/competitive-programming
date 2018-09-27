import os
import re

regex = re.compile(r"-+")
for root, folders, files in os.walk("."):
    if root != "." and root != ".git":
        for each in files:
            old = each
            each = each.replace(" ", '-')
            each = each.replace("_", '-')
            each = regex.sub('-', each)
            old = os.path.join(root, old)
            each = os.path.join(root, each)
            os.rename(old, each)
            print(old, each)
