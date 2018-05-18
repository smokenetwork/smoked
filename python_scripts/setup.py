from setuptools import setup

setup( name='smokedebugnode',
       version='0.1',
       description='A wrapper for launching and interacting with a Smoke Debug Node',
       url='https://gitlab.com/smoke.network/smoked',
       author='Smoke, Inc.',
       author_email='hello@smoke.io',
       license='See LICENSE.md',
       packages=['smokedebugnode'],
       #install_requires=['smokeapi'],
       zip_safe=False )