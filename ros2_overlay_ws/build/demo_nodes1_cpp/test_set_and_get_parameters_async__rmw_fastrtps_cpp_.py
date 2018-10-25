# generated from demo_nodes_cpp/test/test_executables_tutorial.py.in
# generated code does not contain a copyright notice

import os

from launch.legacy import LaunchDescriptor
from launch.legacy.exit_handler import ignore_exit_handler
from launch.legacy.exit_handler import primary_ignore_returncode_exit_handler
from launch.legacy.launcher import DefaultLauncher
from launch.legacy.output_handler import ConsoleOutput
from launch_testing import create_handler
from launch_testing import get_default_filtered_prefixes


def setup():
    os.environ['OSPL_VERBOSITY'] = '8'  # 8 = OS_NONE
    # bare minimum formatting for console output matching
    os.environ['RCUTILS_CONSOLE_OUTPUT_FORMAT'] = '{message}'


def test_executable():
    output_handlers = []

    launch_descriptor = LaunchDescriptor()

    rmw_implementation = 'rmw_fastrtps_cpp'
    executables = ''.split(';')
    output_files = ''.split(';')
    for i, (exe, output_file) in enumerate(zip(executables, output_files)):
        name = 'test_executable_' + str(i)
        # The last executable is taken to be the test program (the one whose
        # output check can make the decision to shut everything down)
        if i == (len(executables) - 1):
            exit_handler = primary_ignore_returncode_exit_handler
            exit_on_match = True
        else:
            exit_handler = ignore_exit_handler
            exit_on_match = False

        filtered = get_default_filtered_prefixes() + [b'service not available, waiting again...']
        handler = create_handler(
            name, launch_descriptor, output_file, filtered_prefixes=filtered,
            exit_on_match=exit_on_match, filtered_rmw_implementation=rmw_implementation)
        assert handler, 'Cannot find appropriate handler for %s' % output_file
        output_handlers.append(handler)
        launch_descriptor.add_process(
            cmd=[exe],
            name=name,
            exit_handler=exit_handler,
            output_handlers=[ConsoleOutput(), handler],
        )

    launcher = DefaultLauncher()
    launcher.add_launch_descriptor(launch_descriptor)
    rc = launcher.launch()

    assert rc == 0, \
        "The launch file failed with exit code '" + str(rc) + "'. " \
        'Maybe the client did not receive any messages?'

    for handler in output_handlers:
        handler.check()


if __name__ == '__main__':
    test_executable()