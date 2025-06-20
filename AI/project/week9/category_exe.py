# -*- coding: utf-8 -*-
"""category_exe.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/19EcE5mzF4eREDUmzUBfBzp76Z3BYPMRU

아래 문자열 입력을 정수형으로 변경하고 print하는 code를 작성하시오
"""

import numpy as np
from sklearn.preprocessing import LabelEncoder
X = np.array(['apple','grape','melon','orange'])

labelEncoder = LabelEncoder()
X = labelEncoder.fit_transform(X)
print(X)

"""아래 문자열 입력을 원 핫 인코딩으로 변경하고 print하는 code를 작성하시오."""

import numpy as np
from sklearn.preprocessing import OneHotEncoder
X = np.array(['apple','grape','melon','orange'])

onehotencoder = OneHotEncoder()
XX = onehotencoder.fit_transform(X.reshape(-1, 1)).toarray()

print(XX)

"""아래 class vector를 원 핫 인코딩으로 변경하고 print하는  code를 작성하시오."""

from tensorflow import keras
import numpy as np
from sklearn.preprocessing import OneHotEncoder

class_vector = np.array([8, 3, 2, 5])

onehotencoder = OneHotEncoder()

print(onehotencoder.fit_transform(class_vector.reshape(-1, 1)).toarray())