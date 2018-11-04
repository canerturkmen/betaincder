import io
import os

try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup
    from distutils.extension import Extension

DESCRIPTION = "compute the incomplete Beta function and its derivatives"
CLASSIFIERS = [
    'Programming Language :: Python :: 2.7',
    'Programming Language :: Python :: 3.6',
    'Programming Language :: Cython',
    'Development Status :: 2 - Pre-Alpha',
    'Intended Audience :: Developers',
    'Intended Audience :: Science/Research',
    'License :: OSI Approved :: MIT License',
    'Topic :: Scientific/Engineering',
    'Topic :: Scientific/Engineering :: Information Analysis',
    'Topic :: Scientific/Engineering :: Mathematics'
]

# make description
try:
    here = os.path.abspath(os.path.dirname(__file__))
    with io.open(os.path.join(here, 'README.md'), encoding='utf-8') as f:
        LONG_DESCRIPTION = '\n' + f.read()
except:
    LONG_DESCRIPTION = DESCRIPTION

extension = [Extension("betaincder.c.betaincder", ["betaincder/c/betaincder.c"],
                               libraries=["m"], extra_compile_args=["-O3", "-march=native", "-std=c99"])]

setup(name="betaincder",
      version="0.1.1",
      description=DESCRIPTION,
      long_description=LONG_DESCRIPTION,
      long_description_content_type="text/markdown",
      author="Caner Turkmen",
      author_email="caner.turkmen@boun.edu.tr",
      ext_modules=extension,
      packages=["betaincder", "betaincder.c"],
      setup_requires=["Cython"],
      license="MIT",
      package_dir={'betaincder.c': 'betaincder/c/'},
      package_data={'betaincder.c': ['*.pxd', '*.h', '*.c']},
      classifiers=CLASSIFIERS
)
